#pragma once

#include "JobQueue.h"

namespace FrokEngine
{
	// 사람이 들어오고 나가는 등의 작업을 처리하는 클래스
	/* 우리가 보통 유저들이 서버라고 부르는 개념이 이 단위이다. */
	class GameRoom : public JobQueue
	{
	public:
		// 플레이어 관련
		void Enter(PlayerRef player);
		void Leave(PlayerRef player);
		void Broadcast(SendBufferRef sendBuffer);
		void SetPlayerPos(uint64 networkID, Protocol::PosInfo posInfo, Protocol::CreatureState animState);
		void Attack(Protocol::C_ATTACK& attackPkt);
		int GetPlayerNum() const { return _players.size(); }

	private :
		void SendOtherPlayerDataToPlayer(PlayerRef player);
		void SendEnterPlayerDataToOther(PlayerRef player);
		void SendFieldMonstersDataToPlayer(PlayerRef player);

		void SendLeavePlayerDataToOther(PlayerRef player);

	public : 
		void Update();

		// 몬스터 관련
		void InitMonsterSet();
		void CheckNearMonster();
		int GetMonsterNum() const { return _monsters.size(); }

	private:
		USE_LOCK;
		map<uint64, PlayerRef> _players;
		map<uint64, MonsterRef> _monsters;
	};

	extern shared_ptr<GameRoom> GRoom;
}
