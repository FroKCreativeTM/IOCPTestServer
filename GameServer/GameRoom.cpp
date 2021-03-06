#include "pch.h"
#include "GameRoom.h"
#include "Contents/Object/Player.h"
#include "GameSession.h"

#include "ClientPacketHandler.h"

namespace FrokEngine
{
	shared_ptr<GameRoom> GRoom = make_shared<GameRoom>();

	void GameRoom::Enter(PlayerRef player)
	{
		if (player == nullptr) return;

		_players[player->objectInfo.objectid()] = player;

		// TODO : DB에서 원래 플레이어가 있던 위치를 보내준다.
		// 즉 원래는 C_ENTER_GAME으로 접속하는 플레이어에 대한 id값만 보내는 식인 것

		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.mutable_player()->set_objectid(static_cast<int32>(player->objectInfo.objectid()));

		// DB -> 내가 게임을 끌 때 
		// 그 최종값을 저장을 해두겠지?
		// 그럼 거기다가 스폰을 시킨다

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		player->ownerSession->Send(sendBuffer);

		// 지금 이미 입장한 사람들에 대한 정보를 지금 접속한 플레이어한테 보낸다.
		for (auto otherPlayer : _players)
		{
			cout << otherPlayer.first << endl;
			cout << player->objectInfo.objectid() << endl;
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.set_playerid(otherPlayer.second->objectInfo.objectid());

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_object()->mutable_posinfo();
				posInfo->set_posx(otherPlayer.second->objectInfo.mutable_posinfo()->posx());
				posInfo->set_posy(otherPlayer.second->objectInfo.mutable_posinfo()->posy());
				posInfo->set_posz(otherPlayer.second->objectInfo.mutable_posinfo()->posz());
				posInfo->set_yaw(otherPlayer.second->objectInfo.mutable_posinfo()->yaw());
				posInfo->set_pitch(otherPlayer.second->objectInfo.mutable_posinfo()->pitch());
				posInfo->set_roll(otherPlayer.second->objectInfo.mutable_posinfo()->roll());
				posInfo->set_velox(otherPlayer.second->objectInfo.mutable_posinfo()->velox());
				posInfo->set_veloy(otherPlayer.second->objectInfo.mutable_posinfo()->veloy());
				posInfo->set_veloz(otherPlayer.second->objectInfo.mutable_posinfo()->veloz());

				cout << "Spawned Other ID : " << otherPlayer.second->objectInfo.objectid() << endl;
				cout << "Position X : " << spawnGamePkt.object().posinfo().posx()
					<< " Y : " << spawnGamePkt.object().posinfo().posy()
					<< " Z : " << spawnGamePkt.object().posinfo().posz() << endl;

				cout << "Rotation Yaw : " << spawnGamePkt.object().posinfo().yaw()
					<< " Roll : " << spawnGamePkt.object().posinfo().roll()
					<< " Pitch : " << spawnGamePkt.object().posinfo().pitch() << endl;

				cout << "Velocity X : " << spawnGamePkt.object().posinfo().velox()
					<< " Y : " << spawnGamePkt.object().posinfo().veloy()
					<< " Z : " << spawnGamePkt.object().posinfo().veloz() << endl << endl;

				sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				player->ownerSession->Send(sendBuffer);
			}
		}

		// 내가 접속했다는 사실을 다른 사람들에게도 보내준다.
		for (auto otherPlayer : _players)
		{
			cout << otherPlayer.first << endl;
			cout << player->objectInfo.objectid() << endl;
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.set_playerid(player->objectInfo.objectid());

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_object()->mutable_posinfo();
				posInfo->set_posx(player->objectInfo.mutable_posinfo()->posx());
				posInfo->set_posy(player->objectInfo.mutable_posinfo()->posy());
				posInfo->set_posz(player->objectInfo.mutable_posinfo()->posz());
				posInfo->set_yaw(player->objectInfo.mutable_posinfo()->yaw());
				posInfo->set_pitch(player->objectInfo.mutable_posinfo()->pitch());
				posInfo->set_roll(player->objectInfo.mutable_posinfo()->roll());
				posInfo->set_velox(player->objectInfo.mutable_posinfo()->velox());
				posInfo->set_veloy(player->objectInfo.mutable_posinfo()->veloy());
				posInfo->set_veloz(player->objectInfo.mutable_posinfo()->veloz());

				cout << "Spawned My ID : " << player->objectInfo.objectid() << endl;
				cout << "Position X : " << spawnGamePkt.object().posinfo().posx()
					<< " Y : " << spawnGamePkt.object().posinfo().posy()
					<< " Z : " << spawnGamePkt.object().posinfo().posz() << endl;

				cout << "Rotation Yaw : " << spawnGamePkt.object().posinfo().yaw()
					<< " Roll : " << spawnGamePkt.object().posinfo().roll()
					<< " Pitch : " << spawnGamePkt.object().posinfo().pitch() << endl;

				cout << "Velocity X : " << spawnGamePkt.object().posinfo().velox()
					<< " Y : " << spawnGamePkt.object().posinfo().veloy()
					<< " Z : " << spawnGamePkt.object().posinfo().veloz() << endl << endl;

				sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::Leave(PlayerRef player)
	{
		// TODO : DB에 현재 유저가 있던 위치를 저장한다.

		_players.erase(player->objectInfo.objectid());

		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_DESPAWN despawnGamePkt;
				despawnGamePkt.set_playerid(player->objectInfo.objectid());

				auto sendBuffer = ClientPacketHandler::MakeSendBuffer(despawnGamePkt);
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::Broadcast(SendBufferRef sendBuffer)
	{
		for (auto& p : _players)
		{
			p.second->ownerSession->Send(sendBuffer);
		}
	}

	void GameRoom::SetPlayerPos(uint64 networkID, Protocol::PosInfo posInfo)
	{
		_players[networkID]->objectInfo.mutable_posinfo()->set_posx(posInfo.posx());
		_players[networkID]->objectInfo.mutable_posinfo()->set_posy(posInfo.posy());
		_players[networkID]->objectInfo.mutable_posinfo()->set_posz(posInfo.posz());

		_players[networkID]->objectInfo.mutable_posinfo()->set_yaw(posInfo.yaw());
		_players[networkID]->objectInfo.mutable_posinfo()->set_roll(posInfo.roll());
		_players[networkID]->objectInfo.mutable_posinfo()->set_pitch(posInfo.pitch());

		_players[networkID]->objectInfo.mutable_posinfo()->set_velox(posInfo.velox());
		_players[networkID]->objectInfo.mutable_posinfo()->set_veloy(posInfo.veloy());
		_players[networkID]->objectInfo.mutable_posinfo()->set_veloz(posInfo.veloz());

		cout << "ID : " << networkID << endl;
		cout << "Position X : " << posInfo.posx()
			<< " Y : " << posInfo.posy()
			<< " Z : " << posInfo.posz() << endl;

		cout << "Rotation Yaw : " << posInfo.yaw()
			<< " Roll : " << posInfo.roll()
			<< " Pitch : " << posInfo.pitch() << endl;

		cout << "Velocity X : " << posInfo.velox()
			<< " Y : " << posInfo.veloy()
			<< " Z : " << posInfo.veloz() << endl << endl;

		Protocol::S_MOVE movePacket;

		movePacket.set_playerid(networkID);

		// 스폰하는 캐릭터에 대한 정보를 보낸다.
		auto myPosInfo = movePacket.mutable_posinfo();
		myPosInfo->set_posx(posInfo.posx());
		myPosInfo->set_posy(posInfo.posy());
		myPosInfo->set_posz(posInfo.posz());
		myPosInfo->set_yaw(posInfo.yaw());
		myPosInfo->set_pitch(posInfo.pitch());
		myPosInfo->set_roll(posInfo.roll());
		myPosInfo->set_velox(posInfo.velox());
		myPosInfo->set_veloy(posInfo.veloy());
		myPosInfo->set_veloz(posInfo.veloz());

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(movePacket);

		// 다른 사람들에게도 보내준다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != networkID)
			{
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}
}