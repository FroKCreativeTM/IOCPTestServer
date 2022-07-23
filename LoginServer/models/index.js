import Sequelize from 'sequelize';
import { Account } from './account.js';

const env = process.env.NODE_ENV || 'development';

import jsonObject from "../config/config.json";
const config = jsonObject[env];
const db = {};

const sequelize = new Sequelize(config.database, config.username, config.password, config);

db.sequelize = sequelize;
db.Sequelize = Sequelize;

db.Account = Account;

Account.init(sequelize);

// Account.associate(db);

export { db };