#pragma once

#include "JobQueue.h"

namespace FrokEngine
{
	// ����� ������ ������ ���� �۾��� ó���ϴ� Ŭ����
	/* �츮�� ���� �������� ������� �θ��� ������ �� �����̴�. */
	class GameRoom : public JobQueue
	{
	public:
		// �÷��̾� ����
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

		// ���� ����
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
