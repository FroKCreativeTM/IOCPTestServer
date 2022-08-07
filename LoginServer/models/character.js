import Sequelize from 'sequelize';

class Character extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
        id: {
          type: Sequelize.STRING(20),
          allowNull: false,
          unique: true,
          primaryKey: true,
        },
        characterName: {
          type: Sequelize.STRING(20),
          allowNull: false,
        },
        level: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
        hp: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
        mp: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
        exp: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
        gold: {
          type: Sequelize.INTEGER,
          allowNull: false,
        },
    }, {
      sequelize,
      timestamps: false,
      underscored: false,
      modelName: 'Character',
      tableName: 'characters',
      paranoid: false,
      charset: 'utf8',
      collate: 'utf8_general_ci',
    });
  }
};

export { Character };