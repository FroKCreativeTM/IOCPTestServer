import Sequelize from 'sequelize';

class ServerInfo extends Sequelize.Model {
  static init(sequelize) {
    return super.init({
      ServerDBId: {
        type: Sequelize.INTEGER,
        allowNull: false,
        unique: true,
        primaryKey: true,
      },
      ServerName: {
        type: Sequelize.TEXT('long'),
        allowNull: false,
      },
      IPAddress: {
        type: Sequelize.TEXT('long'),
        allowNull: false,
      },
      Port: {
        type: Sequelize.INTEGER,
        allowNull: false,
      },
      BusyScore: {
        type: Sequelize.INTEGER,
        allowNull: false,
      },
    }, {
      sequelize,
      timestamps: false,
      underscored: false,
      modelName: 'ServerInfo',
      tableName: 'serverinfos',
      paranoid: false,
      charset: 'utf8',
      collate: 'utf8_general_ci',
    });
  }

    // TODO : 서버 목록 보내기
    // 서버 이름, IP, 포트, 혼잡도(Crowded level) - 문제, 혼잡도는 게임 서버만 안다.
    // 고로 게임 서버와 로그인 서버를 연동할 필요가 있다.
    // SharedDB를 이용해볼까?

    // SharedDB에 중요한것
    // Table("Token")
    // 1. 토큰(AccountServer에서도 인증 받은 걸 게임 서버도 알아야된다.)
    // 1.1. TokenDBID - 번호표같은 AccountServer에서 인증받음을 증명
    // 1.2. AccountDBID - 내가 인증받은 Account의 ID
    // 1.3. Token (이건 뭐 UUID) - 실시간 랜덤 토큰 값
    // 1.4. Created, Expired (사실 Expired가 있으면 Created 시간이 필요있을까 싶음)
    // - 들어갈 때 게임 서버 쪽에 알려준다.
};

export { ServerInfo };