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

		_players[player->playerId] = player;

		// TODO : DB에서 원래 플레이어가 있던 위치를 보내준다.
		// 즉 원래는 C_ENTER_GAME으로 접속하는 플레이어에 대한 id값만 보내는 식인 것

		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.mutable_player()->set_objectid(static_cast<int32>(player->playerId));

		// DB -> 내가 게임을 끌 때 
		// 그 최종값을 저장을 해두겠지?
		// 그럼 거기다가 스폰을 시킨다

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		player->ownerSession->Send(sendBuffer);

		// 지금 이미 입장한 사람들에 대한 정보를 지금 접속한 플레이어한테 보낸다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->playerId)
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.set_playerid(otherPlayer.second->playerId);

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_object()->mutable_posinfo();
				posInfo->set_posx(otherPlayer.second->pos.posx());
				posInfo->set_posy(otherPlayer.second->pos.posy());
				posInfo->set_posz(otherPlayer.second->pos.posz());
				posInfo->set_yaw(otherPlayer.second->pos.yaw());
				posInfo->set_pitch(otherPlayer.second->pos.pitch());
				posInfo->set_roll(otherPlayer.second->pos.roll());
				posInfo->set_velox(otherPlayer.second->pos.velox());
				posInfo->set_veloy(otherPlayer.second->pos.veloy());
				posInfo->set_veloz(otherPlayer.second->pos.veloz());

				cout << "Spawned Other ID : " << otherPlayer.second->playerId << endl;
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
			if (otherPlayer.first != player->playerId)
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.set_playerid(player->playerId);

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_object()->mutable_posinfo();
				posInfo->set_posx(player->pos.posx());
				posInfo->set_posy(player->pos.posy());
				posInfo->set_posz(player->pos.posz());
				posInfo->set_yaw(player->pos.yaw());
				posInfo->set_pitch(player->pos.pitch());
				posInfo->set_roll(player->pos.roll());
				posInfo->set_velox(player->pos.velox());
				posInfo->set_veloy(player->pos.veloy());
				posInfo->set_veloz(player->pos.veloz());

				cout << "Spawned My ID : " << player->playerId << endl;
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

		_players.erase(player->playerId);

		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->playerId)
			{
				Protocol::S_DESPAWN despawnGamePkt;
				despawnGamePkt.set_playerid(player->playerId);

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
}