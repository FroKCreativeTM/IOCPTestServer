#include "pch.h"
#include "ClientPacketHandler.h"
#include "GameSession.h"
#include "Player.h"
#include "GameRoom.h"

#include "LoginManager.h"

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
		// 로그인 실패인지 아닌지 판별한다.
		Protocol::S_LOGIN loginPkt;

		// 테스트 코드임
		// Login 부분을 수정할 필요 있음

		// ID 발급 (DB 아이디가 아니고, 인게임 아이디)
		static Atomic<uint64> idGenerator = 1;

		auto password = pkt.password();
		password = SHA256::GetInst()->toString(reinterpret_cast<const uint8_t*>(password.c_str()));

		cout << "id : " << pkt.id() << endl;
		cout << "password : " << password << endl;

		if (LoginManager::GetInst()->Login(pkt.id(), password))
		{
			cout << "로그인 성공" << endl;
			loginPkt.set_success(1);
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
		//GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		//Protocol::S_LOGIN loginPkt;
		//loginPkt.set_success(true);

		//static Atomic<uint64> idGenerator = 1;

		//auto player = loginPkt.add_players();
		//player->set_name(u8"DB에서긁어온이름1");

		//PlayerRef playerRef = MakeShared<Player>();
		//playerRef->playerId = idGenerator++;
		//playerRef->name = player->name();
		//// playerRef->type = player->ge();
		//playerRef->SetOwnerSession(gameSession);

		//gameSession->_players.push_back(playerRef);

		//auto sendBuffer = ClientPacketHandler::MakeSendBuffer(loginPkt);
		//session->Send(sendBuffer);

		cout << "[\tLOG\t]" << endl;
		cout << "Position X : " << pkt.player().posinfo().posx()
			<< " Y : " << pkt.player().posinfo().posy()
			<< " Z : " << pkt.player().posinfo().posz() << endl;

		cout << "Rotation Yaw : " << pkt.player().posinfo().yaw()
			<< " Roll : " << pkt.player().posinfo().roll()
			<< " Pitch : " << pkt.player().posinfo().pitch() << endl;

		cout << "Velocity X : " << pkt.player().posinfo().velox()
			<< " Y : " << pkt.player().posinfo().veloy()
			<< " Z : " << pkt.player().posinfo().veloz() << endl << endl;

		return true;
	}

	bool Handle_C_CURRENT_PLAYER_INFO(PacketSessionRef& session, Protocol::C_CURRENT_PLAYER_INFO& pkt)
	{
		cout << "[\tLOG\t]" << endl;
		cout << "Position X : " << pkt.player().posinfo().posx()
			<< " Y : " << pkt.player().posinfo().posy()
			<< " Z : " << pkt.player().posinfo().posz() << endl;

		cout << "Rotation Yaw : " << pkt.player().posinfo().yaw()
			<< " Roll : " << pkt.player().posinfo().roll()
			<< " Pitch : " << pkt.player().posinfo().pitch() << endl;

		cout << "Velocity X : " << pkt.player().posinfo().velox()
			<< " Y : " << pkt.player().posinfo().veloy()
			<< " Z : " << pkt.player().posinfo().veloz() << endl << endl;

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
	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt)
	{
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