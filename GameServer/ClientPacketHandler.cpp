#include "pch.h"
#include "ClientPacketHandler.h"
#include "Contents/Object/Player.h"
#include "GameRoom.h"
#include "GameSession.h"

#include "Contents/Manager/LoginManager.h"

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	// 직접 컨텐츠 작업자
	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
	{
		// 그 플레이어의 세션을 가져온다.
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		// 로그인 실패인지 아닌지 판별한다.
		Protocol::S_LOGIN loginPkt;

		// 테스트 코드임
		// Login 부분을 수정할 필요 있음

		// ID 발급 (DB 아이디가 아니고, 인게임 아이디)
		static Atomic<uint64> idGenerator = 0;

		auto password = pkt.password();
		password = SHA256::GetInst()->toString(reinterpret_cast<const uint8_t*>(password.c_str()));

		cout << "id : " << pkt.id() << endl;
		cout << "password : " << password << endl;

		if (LoginManager::GetInst()->Login(pkt.id(), password))
		{
			cout << "로그인 성공" << endl;
			loginPkt.set_success(1);
			
			// 그 유저가 가진 캐릭터의 목록을 가져온다.
			auto player = loginPkt.add_players();

			string name = "Player_Actor_" + to_string(++idGenerator);

			player->set_name(name);
			// player->set_playertype(Protocol::PLAYER_TYPE_KNIGHT);

			PlayerRef playerRef = MakeShared<Player>();
			playerRef->playerId = idGenerator;
			playerRef->name = player->name();
			// playerRef->type = player->playertype();
			playerRef->ownerSession = gameSession;

			// 게임 세션에 플레이어를 등록한다.
			gameSession->_players.push_back(playerRef);
		}
		else 
		{
			loginPkt.set_success(0);
		}

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(loginPkt);
		session->Send(sendBuffer);

		return true;
	}

	// 회원 가입에 대한 요청을 처리한다.
	// 만약 회원가입이 되지 않는 상황이라면 이에 대한 사유를 전달한다.
	bool Handle_C_SIGNUP(PacketSessionRef& session, Protocol::C_SIGNUP& pkt)
	{
		// 아직 안 만듬
		// Login 매니저에 Signup에 대한 메서드가 있음
		// 구현 필요함
		return false;
	}

	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
	{
		// 게임 세션을 가져온다.
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		static Atomic<int> idGenerator = 0;

		uint64 index = pkt.playerindex();
		// TODO : Validation

		gameSession->_currentPlayer = gameSession->_players[index]; // READ_ONLY?
		gameSession->_room = GRoom;

		GRoom->DoAsync(&GameRoom::Enter, gameSession->_currentPlayer);

		Protocol::S_ENTER_GAME enterGamePkt;
		
		auto objectInfo = enterGamePkt.mutable_player();
		objectInfo->set_objectid(++idGenerator);

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		gameSession->_currentPlayer->ownerSession->Send(sendBuffer);

		return true;
	}

	bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
	{
		std::cout << pkt.msg() << endl;

		Protocol::S_CHAT chatPkt;
		chatPkt.set_msg(pkt.msg());
		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(chatPkt);

		GRoom->DoAsync(&GameRoom::Broadcast, sendBuffer);

		return true;
	}

	bool Handle_C_SPAWN(PacketSessionRef& session, Protocol::C_SPAWN& pkt)
	{
		return false;
	}

	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt)
	{
		cout << "ID : " << pkt.playerid() << endl;
		cout << "Position X : " << pkt.posinfo().posx()
			<< " Y : " << pkt.posinfo().posy()
			<< " Z : " << pkt.posinfo().posz() << endl;

		cout << "Rotation Yaw : " << pkt.posinfo().yaw()
			<< " Roll : " << pkt.posinfo().roll()
			<< " Pitch : " << pkt.posinfo().pitch() << endl;

		cout << "Velocity X : " << pkt.posinfo().velox()
			<< " Y : " << pkt.posinfo().veloy()
			<< " Z : " << pkt.posinfo().veloz() << endl << endl;

		return true;
	}
}