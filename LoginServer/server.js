import WebSocket, { WebSocketServer } from 'ws';
import { randomUUID } from 'crypto';
const { sequelize } = require('./models');

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
    // send a message to all connected clients upon receiving a message from one of the connected clients
    ws.on('message', (data) => {
        // console.log(`received: ${data}`);
        // serverBroadcast(`Client ${clients.get(ws)} ${data}`);

        const json = JSON.parse(data);
        console.log(json);

        if(json.ActionType === "Login") {
            // 로그인 인 경우 성공시 UUID를 발급해서 전달한다.
            const id = randomUUID();
            clients.set(ws, id);

            // 성공시 uuid를 전달한다.
            ws.send(JSON.stringify({ jsontype : "Login", success : true, UUID : id }));
        } else if(json.ActionType === "SignUp") {
            // 회원 가입의 경우
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
    serverBroadcast(`Number of connected clients: ${clients.size}`);
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