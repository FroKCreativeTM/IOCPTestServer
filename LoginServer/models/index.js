import Sequelize from 'sequelize';
import { Account } from './account.js';
import { Token } from './token.js';
import { Character } from './character.js';
import { ServerInfo } from './serverInfo.js';

const env = process.env.NODE_ENV || 'development';

<<<<<<< HEAD
import jsonObject from "../config/config.json" // assert {type: "json"};
=======
import jsonObject from "../config/config.json" //assert {type: "json"};
>>>>>>> parent of 2e74f45 (todo 리스트 작성)
const config = jsonObject[env];
const db = {};

const sequelize = new Sequelize(config.database, config.username, config.password, config);

db.sequelize = sequelize;
db.Sequelize = Sequelize;

db.Account = Account;
db.Token = Token;
db.Character = Character;
db.ServerInfo = ServerInfo;

Account.init(sequelize);
Token.init(sequelize);
ServerInfo.init(sequelize);
Character.init(sequelize);

// Account.associate(db);
// Token.associate(db);

export { db };