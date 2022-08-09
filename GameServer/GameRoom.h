#pragma once

#include "JobQueue.h"

namespace FrokEngine
{
	// 사람이 들어오고 나가는 등의 작업을 처리하는 클래스
	/* 우리가 보통 유저들이 서버라고 부르는 개념이 이 단위이다. */
	class GameRoom : public JobQueue
	{
	public:
		void Enter(PlayerRef player);
		void Leave(PlayerRef player);
		void Broadcast(SendBufferRef sendBuffer);

		void SetPlayerPos(uint64 networkID, Protocol::PosInfo posInfo, Protocol::CreatureState animState);

		void InitMonsterSet();

	private:
		map<uint64, PlayerRef> _players;
		map<uint64, MonsterRef> _monsters;
	};

	extern shared_ptr<GameRoom> GRoom;
}
