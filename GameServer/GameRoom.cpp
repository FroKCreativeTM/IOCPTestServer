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
	}

	void GameRoom::Leave(PlayerRef player)
	{
		_players.erase(player->playerId);
	}

	void GameRoom::Broadcast(SendBufferRef sendBuffer)
	{
		for (auto& p : _players)
		{
			p.second->ownerSession->Send(sendBuffer);
		}
	}
}