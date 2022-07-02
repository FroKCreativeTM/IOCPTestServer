#include "pch.h"
#include "ClientPacketHandler.h"
#include "GameSession.h"
#include "Contents/Object/Player.h"
#include "GameRoom.h"

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

			player->set_name(u8"");
			// player->set_playertype(Protocol::PLAYER_TYPE_KNIGHT);

			PlayerRef playerRef = MakeShared<Player>();
			playerRef->playerId = idGenerator;
			playerRef->name = player->name();
			// playerRef->type = player->playertype();
			playerRef->ownerSession = gameSession;

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
		//GameSessionRef gameSession = static_pointer_cast<GameSession>(session);

		//Protocol::S_LOGIN loginPkt;
		//loginPkt.set_success(true);

		//static Atomic<uint64> idGenerator = 1;

		//auto player = loginPkt.add_players();
		//player->set_name(u8"DB�����ܾ���̸�1");

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