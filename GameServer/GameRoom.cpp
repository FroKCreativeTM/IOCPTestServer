#include "pch.h"
#include "GameRoom.h"
#include "Player.h"
#include "GameSession.h"

namespace FrokEngine
{
	shared_ptr<GameRoom> GRoom = make_shared<GameRoom>();

	void GameRoom::Enter(PlayerRef player)
	{
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
			p.second->GetOwnerSession()->Send(sendBuffer);
		}
	}
}