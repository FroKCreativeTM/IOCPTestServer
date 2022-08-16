#include "pch.h"
#include "ClientPacketHandler.h"
#include "Contents/Object/Player/Player.h"
#include "GameRoom.h"
#include "GameSession.h"

#include <DBBind.h>

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	// TODO : 로그인, 서버 선택창, 캐릭터 선택창
	// 먼저 로그인 서버에서 만든 토큰을 찾아서 이 사람이 정말 맞는 사람인지 체크한다.
	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
	{
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		static std::atomic<int> idGenerator = 0;

		PlayerRef playerRef = MakeShared<Player>();

		// TODO : SharedDB에서 Token과 함께 가져온다.
		playerRef->objectInfo.set_objectid(idGenerator.fetch_add(1));
		playerRef->objectInfo.set_name("test" + to_string(playerRef->objectInfo.objectid()));
		playerRef->ownerSession = gameSession;

		playerRef->objectInfo.mutable_posinfo()->set_posx(pkt.player().objectinfo().posinfo().posx());
		playerRef->objectInfo.mutable_posinfo()->set_posy(pkt.player().objectinfo().posinfo().posy());
		playerRef->objectInfo.mutable_posinfo()->set_posz(pkt.player().objectinfo().posinfo().posz());

		playerRef->objectInfo.mutable_posinfo()->set_yaw(pkt.player().objectinfo().posinfo().yaw());
		playerRef->objectInfo.mutable_posinfo()->set_pitch(pkt.player().objectinfo().posinfo().pitch());
		playerRef->objectInfo.mutable_posinfo()->set_roll(pkt.player().objectinfo().posinfo().roll());

		playerRef->objectInfo.mutable_posinfo()->set_velox(pkt.player().objectinfo().posinfo().velox());
		playerRef->objectInfo.mutable_posinfo()->set_veloy(pkt.player().objectinfo().posinfo().veloy());
		playerRef->objectInfo.mutable_posinfo()->set_veloz(pkt.player().objectinfo().posinfo().veloz());

		gameSession->_players.push_back(playerRef);

		gameSession->_currentPlayer = playerRef;
		gameSession->_room = GRoom;

		GRoom->DoAsync(&GameRoom::Enter, gameSession->_currentPlayer);

		return true;
	}

	bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
	{
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

		// 현재 그 세션과 연결중인 플레이어에 대한 정보를 지운다.
		// 이후 서버와 세션으로 연결중인 모든 플레이어에게 DESPAWN을 보낸다.
		GRoom->DoAsync(&GameRoom::Leave, gameSession->_currentPlayer);

		return false;
	}

	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt)
	{
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		GRoom->SetPlayerPos(pkt.playerid(), pkt.posinfo(), pkt.creaturestate());

		return true;
	}

	bool Handle_C_ATTACK(PacketSessionRef& session, Protocol::C_ATTACK& pkt)
	{
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
		// TODO : 플레이어가 때린 경우 때린 이와 맞은 이의 거리를 
		// 원형으로 판정해서 간단하게 체크한 뒤 broadcast를 진행한다.

		GRoom->Attack(pkt);

		return true;
	}
}