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
		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		player->ownerSession->Send(sendBuffer);

		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->playerId)
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.set_playerid(player->playerId);

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_posx(player->pos.posx());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_posy(player->pos.posy());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_posz(player->pos.posz());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_yaw(player->pos.yaw());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_pitch(player->pos.pitch());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_roll(player->pos.roll());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_velox(player->pos.velox());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_veloy(player->pos.veloy());
				spawnGamePkt.mutable_object()->mutable_posinfo()->set_veloz(player->pos.veloz());

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