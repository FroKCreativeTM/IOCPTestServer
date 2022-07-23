import WebSocket, { WebSocketServer } from 'ws';
import { randomUUID } from 'crypto';
import { db } from './models/index.js';
import bcrypt  from 'bcrypt';

const sequelize = db.sequelize;
const Account = db.Account;

const clients = new Map(); // has to be a Map instead of {} due to non-string keys
const wss = new WebSocketServer({ port: 7776 }); //로그인 서버 포트 번호는 7776입니다.

sequelize.sync({ force: false })
.then(() => {
    console.log('데이터베이스 연결 성공');
})
.catch((err) => {
    console.error(err);
});

// set up event handlers and do other things upon a client connecting to the server
wss.on('connection', (ws) => {
    ws.on('message', async (data) => {
        const json = JSON.parse(data);
        console.log(json);

        if(json.ActionType === "Login") {
            try {
                const account = await Account.findOne({ where : { id : json.PlayerID } });

                if(account) {
                    console.log(account.password);
                    const result = await bcrypt.compare(json.PlayerPassword, account.password);

                    if(result) {
                        // 성공시 UUID를 발급해서 전달한다.
                        const id = randomUUID();
                        clients.set(ws, id);
    
                        // uuid를 전달한다.
                        ws.send(JSON.stringify({ jsontype : "Login", success : true, UUID : id }));
                    } else {
                        ws.send(JSON.stringify({ jsontype : "Login", success : false, errorcode : 1 }));
                    }
                } else {
                    ws.send(JSON.stringify({ jsontype : "Login", success : false, errorcode : 2 }));
                }
            } catch(err) {
                console.error(err);
                // 서버 내부 에러라는 의미에서 500
                ws.send(JSON.stringify({ jsontype : "Login", success : false, errorcode : 500 }));
            }

        } else if(json.ActionType === "SignUp") {
            // 회원 가입의 경우
            try {
                const account = await Account.findOne({ where : { id : json.PlayerID } });
                
                if(account) {
                    // 회원이 있는 것이니 Out
                    ws.send(JSON.stringify({ jsontype : "SignUp", success : false , errorcode : 3}));
                } else {
                    const hash = await bcrypt.hash(json.PlayerPassword, 12);
                    console.log(hash);
                    await Account.create({
                        id : json.PlayerID,
                        password: hash,
                    });

                    ws.send(JSON.stringify({ jsontype : "SignUp", success : true }));
                }
            } catch(err) {
                console.error(err);
                ws.send(JSON.stringify({ jsontype : "SignUp", success : false, errorcode : 500 }));
            }
        }
    });

    // stop tracking the client upon that client closing the connection
    ws.on('close', () => {
        console.log(`connection (id = ${clients.get(ws)}) closed`);
        clients.delete(ws);
    });
});

// send a message to all the connected clients about how many of them there are every 15 seconds
setInterval(() => {
    console.log(`Number of connected clients: ${clients.size}`);
//     serverBroadcast(`Number of connected clients: ${clients.size}`);
}, 15000);

// function for sending a message to every connected client
function serverBroadcast(message) {
    wss.clients.forEach((client) => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(message);
        }
    });
}

console.log('The server is running and waiting for connections');