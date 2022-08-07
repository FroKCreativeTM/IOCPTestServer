import WebSocket, { WebSocketServer } from 'ws';
import { randomUUID } from 'crypto';
import { db } from './models/index.js';
import bcrypt  from 'bcrypt';

const sequelize = db.sequelize;
const Account = db.Account;
const ServerInfo = db.ServerInfo;
const Token = db.Token;
const Character = db.Character;

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
wss.on('connection', async (ws) => {
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
                        // TODO : 서버 목록 보내기
                        // 서버 이름, IP, 포트, 혼잡도(Crowded level) - 문제, 혼잡도는 게임 서버만 안다.
                        // 고로 게임 서버와 로그인 서버를 연동할 필요가 있다.
                        // SharedDB를 이용해볼까? - 장점)프로세스를 따로 팔 필요가 없어서, 메모리와 시간을 둘 다 아낄 수 있음
                        // 사실 sharedDB 말고도 레디스를 이용해서 메모리 DB를 공용으로 사용하게 하는 방법도 존재한다.
                        
                        // 의사 코드
                        // DateTime expired = Date.Now + AddSecond(600);
                        // tokenDB =  TokenTable.where(t => t.accountDBID == account.accountDBID);
                        // if(tokenDB) 
                        // {
                        //      tokenDB.Token = RandomUUID -> 위에서는 id;
                        //      tokenDB.Expired = expired;
                        //      update(tokenDB);
                        // } 
                        // else 
                        // {
                        //      tokenDB = new tokenDB();
                        //      tokenDB.AccountDBID = json.PlayerID;
                        //      tokenDB.Token = id;
                        //      tokenDB.Expired = expired;
                        //      
                        //      insert(tokenDB);
                        // }

                        // 성공시 UUID를 발급해서 전달한다.
                        const id = randomUUID();
                        clients.set(ws, id);

                        // 만료 시간을 구한다. (10분 정도로 둔다.)
                        let expired = new Date(); 
                        expired = expired.getSeconds() + 600;

                        const token = await Token.findOne({ where : { AccountID : json.PlayerID } });

                        if(token)
                        {
                            await Token.update(
                                {
                                    Token : id,
                                    Expired : expired
                                },
                                {
                                    where : { AccountID : json.PlayerID },
                                }
                            );
                        }
                        else
                        {   
                            // 토큰 정보를 SharedDB에 넣는다.
                            await Token.create({
                                AccountID : json.PlayerID,
                                Token : id,
                                Expired : expired
                            });
                        }

                        let serverInfos = await ServerInfo.findAll();
                        console.log(serverInfos);
                        // uuid를 전달한다.
                        // 그리고 현재 serverinfo들을 같이 보내준다.
                        ws.send(JSON.stringify({ jsontype : "Login", success : true, UUID : id, serverInfo : serverInfos }));

                        // 상식!
                        // AccountDB와 Token을 중간에 가로채면 어떻게 하지?
                        // 외부로 보낼 때 HTTPS에서 SSL을 켜서 운영하면, 비대칭키 알고리즘을 이용해서 암호화되기 때문에
                        // 외부에서 모른다! (정확히는 탈취해봐야 의미가 없다.)

                        // Table("ServerInfo")
                        // ServerDBId - 주키
                        // 서버의 이름
                        // IP Address, Port
                        // 지금 서버의 상황(Busy 여부)
                        
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
    ws.on('close', async () => {
        console.log(`connection (id = ${clients.get(ws)}) closed`);

        //await Token.destroy({
         //   where : {
          //      Token : clients.get(ws),
           // }});

        clients.delete(ws);
    });
});

// TODO 대충 10분마다 한 번씩 token이 만료되었으면서 동시에, 
// 게임을 끈 사람들을 체크해서, 이들의 연결을 끊는다.
setInterval(() => {
    console.log(`Number of connected clients: ${clients.size}`);
//     serverBroadcast(`Number of connected clients: ${clients.size}`);
}, 600000);

// function for sending a message to every connected client
function serverBroadcast(message) {
    wss.clients.forEach((client) => {
        if (client.readyState === WebSocket.OPEN) {
            client.send(message);
        }
    });
}

console.log('The server is running and waiting for connections');