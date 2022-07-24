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

  // TODO : 1대 다 형상으로 
  // 현재 이 사람의 캐릭터 리스트를 가진다.
  // 이 때 ID 값을 외래 키로 넘긴다.
  // 이 사람이 삭제된다면 캐릭터 리스트도 삭제되게 만든다.
};

export { Account };