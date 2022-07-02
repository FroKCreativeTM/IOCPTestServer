#pragma once

#include "JobQueue.h"

namespace FrokEngine
{
	// ����� ������ ������ ���� �۾��� ó���ϴ� Ŭ����
	/* �츮�� ���� �������� ������� �θ��� ������ �� �����̴�. */
	class GameRoom : public JobQueue
	{
	public:
		void Enter(PlayerRef player);
		void Leave(PlayerRef player);
		void Broadcast(SendBufferRef sendBuffer);

	private:
		map<uint64, PlayerRef> _players;
	};

	extern shared_ptr<GameRoom> GRoom;
}
