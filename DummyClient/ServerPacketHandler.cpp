#include "pch.h"
#include "ServerPacketHandler.h"

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	// Á÷Á¢ ÄÁÅÙÃ÷ ÀÛ¾÷ÀÚ

	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	bool Handle_S_ENTER_GAME(PacketSessionRef& session, Protocol::S_ENTER_GAME& pkt)
	{
		// TODO
		return true;
	}

	bool Handle_S_CHAT(PacketSessionRef& session, Protocol::S_CHAT& pkt)
	{
		std::cout << pkt.msg() << endl;
		return true;
	}

	bool Handle_S_SPAWN(PacketSessionRef& session, Protocol::S_SPAWN& pkt)
	{
		return false;
	}
	bool Handle_S_MOVE(PacketSessionRef& session, Protocol::S_MOVE& pkt)
	{
		return false;
	}
}