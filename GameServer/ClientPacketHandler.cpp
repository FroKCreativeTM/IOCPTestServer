#include "pch.h"
#include "ClientPacketHandler.h"
#include "Contents/Object/Player.h"
#include "GameRoom.h"
#include "GameSession.h"

#include "Contents/Object/Player.h"

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

	//bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
	//{
	//	return true;
	//}

	// 회원 가입에 대한 요청을 처리한다.
	// 만약 회원가입이 되지 않는 상황이라면 이에 대한 사유를 전달한다.
	//bool Handle_C_SIGNUP(PacketSessionRef& session, Protocol::C_SIGNUP& pkt)
	//{
	//	return false;
	//}

	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
	{
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		cout << "Enter Game" << endl;

		static std::atomic<int> idGenerator = 0;

		PlayerRef playerRef = MakeShared<Player>();
		playerRef->playerId = idGenerator.fetch_add(1);
		playerRef->name = "test" + to_string(playerRef->playerId);
		playerRef->ownerSession = gameSession;

		cout << "player id : " << playerRef->playerId << endl;

		gameSession->_players.push_back(playerRef);

		gameSession->_currentPlayer = playerRef;
		gameSession->_room = GRoom;

		GRoom->DoAsync(&GameRoom::Enter, gameSession->_currentPlayer);

		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.mutable_player()->set_objectid(static_cast<int32>(playerRef->playerId));
		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		session->Send(sendBuffer);

		Protocol::S_SPAWN spawnGamePkt;
		sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
		for (auto otherPlayer : gameSession->_players)
		{
			if (otherPlayer->playerId != gameSession->_currentPlayer->playerId)
			{
				otherPlayer->ownerSession->Send(sendBuffer);
			}
		}

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
		return true;
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