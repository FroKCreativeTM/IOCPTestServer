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
	// 
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

	bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt)
	{
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		cout << "Leave Game packet id : " << pkt.leaveplayer().objectid() << endl;
		cout << "Leave Game player id : " << gameSession->_currentPlayer->playerId << endl;

		// 현재 그 세션과 연결중인 플레이어에 대한 정보를 지운다.
		// 이후 서버와 세션으로 연결중인 모든 플레이어에게 DESPAWN을 보낸다.
		GRoom->DoAsync(&GameRoom::Leave, gameSession->_currentPlayer);

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