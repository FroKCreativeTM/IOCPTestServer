import Sequelize from 'sequelize';

class Account extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
      id: {
        type: Sequelize.STRING(20),
        allowNull: false,
        unique: true,
        primaryKey: true,
      },
      password: {
        type: Sequelize.TEXT('long'),
        allowNull: false,
      },
      created_at: {
        type: Sequelize.DATE,
        allowNull: false,
        defaultValue: Sequelize.NOW,
      },
    }, {
      sequelize,
      timestamps: false,
      underscored: false,
      modelName: 'Account',
      tableName: 'accounts',
      paranoid: false,
      charset: 'utf8',
      collate: 'utf8_general_ci',
    });
  }
};

export { Account };