#include "pch.h"
#include "ClientPacketHandler.h"
#include "GameSession.h"
#include "Contents/Manager/LoginManager.h"

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
	{
		return true;
	}
	 
	bool Handle_C_SIGNUP(PacketSessionRef& session, Protocol::C_SIGNUP& pkt)
	{
		return false;
	}

	// TODO : 로그인, 서버 선택창, 캐릭터 선택창

	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
	{
		// 게임 컨텐츠 서버쪽에서 관리
		return true;
	}

	bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
	{
		// 게임 컨텐츠 서버쪽에서 관리
		return true;
	}

	bool Handle_C_SPAWN(PacketSessionRef& session, Protocol::C_SPAWN& pkt)
	{
		// 게임 컨텐츠 서버쪽에서 관리
		return true;
	}

	bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt)
	{
		// 게임 컨텐츠 서버쪽에서 관리
		return true;
	}

	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt)
	{
		// 게임 컨텐츠 서버쪽에서 관리
		return true;
	}
}