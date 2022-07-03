#include "pch.h"
#include "ClientPacketHandler.h"
#include "Contents/Object/Player.h"
#include "GameRoom.h"
#include "GameSession.h"

#include "Contents/Manager/LoginManager.h"

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	// ���� ������ �۾���
	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
	{
		// �� �÷��̾��� ������ �����´�.
		GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		// �α��� �������� �ƴ��� �Ǻ��Ѵ�.
		Protocol::S_LOGIN loginPkt;

		// �׽�Ʈ �ڵ���
		// Login �κ��� ������ �ʿ� ����

		// ID �߱� (DB ���̵� �ƴϰ�, �ΰ��� ���̵�)
		static Atomic<uint64> idGenerator = 0;

		auto password = pkt.password();
		password = SHA256::GetInst()->toString(reinterpret_cast<const uint8_t*>(password.c_str()));

		cout << "id : " << pkt.id() << endl;
		cout << "password : " << password << endl;

		if (LoginManager::GetInst()->Login(pkt.id(), password))
		{
			cout << "�α��� ����" << endl;
			loginPkt.set_success(1);
			
			// �� ������ ���� ĳ������ ����� �����´�.
			auto player = loginPkt.add_players();

			string name = "Player_Actor_" + to_string(++idGenerator);

			player->set_name(name);
			// player->set_playertype(Protocol::PLAYER_TYPE_KNIGHT);

			PlayerRef playerRef = MakeShared<Player>();
			playerRef->playerId = idGenerator;
			playerRef->name = player->name();
			// playerRef->type = player->playertype();
			playerRef->ownerSession = gameSession;

			// ���� ���ǿ� �÷��̾ ����Ѵ�.
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

	// ȸ�� ���Կ� ���� ��û�� ó���Ѵ�.
	// ���� ȸ�������� ���� �ʴ� ��Ȳ�̶�� �̿� ���� ������ �����Ѵ�.
	bool Handle_C_SIGNUP(PacketSessionRef& session, Protocol::C_SIGNUP& pkt)
	{
		// ���� �� ����
		// Login �Ŵ����� Signup�� ���� �޼��尡 ����
		// ���� �ʿ���
		return false;
	}

	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
	{
		// ���� ������ �����´�.
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