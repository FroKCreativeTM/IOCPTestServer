import Sequelize from 'sequelize';
import { Account } from './account.js';
import { Token } from './token.js';
import { ServerInfo } from './serverInfo.js';

const env = process.env.NODE_ENV || 'development';

import jsonObject from "../config/config.json" //assert {type: "json"};
const config = jsonObject[env];
const db = {};

const sequelize = new Sequelize(config.database, config.username, config.password, config);

db.sequelize = sequelize;
db.Sequelize = Sequelize;

db.Account = Account;
db.Token = Token;
db.ServerInfo = ServerInfo;

Account.init(sequelize);
Token.init(sequelize);
ServerInfo.init(sequelize);

// Account.associate(db);
// Token.associate(db);

export { db };