#pragma once
#include "Session.h"
#include "Contents/Object/Player.h"

namespace FrokEngine
{
	class GameSession : public PacketSession
	{
	public:
		~GameSession()
		{
			cout << "~GameSession" << endl;
		}

		virtual void OnConnected() override;
		virtual void OnDisconnected() override;
		virtual void OnRecvPacket(BYTE* buffer, int32 len) override;
		virtual void OnSend(int32 len) override;

	public:
		// 현재 접속한 플레이어 정보
		Vector<PlayerRef> _players;

		PlayerRef _currentPlayer;
		weak_ptr<class GameRoom> _room;
	};
}