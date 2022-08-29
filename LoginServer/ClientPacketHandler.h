#pragma once
#include "Protocol.pb.h"

namespace FrokEngine
{
	using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
	extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

	enum : uint16
	{
		PKT_C_ENTER_GAME = 0,
		PKT_S_ENTER_GAME = 1,
		PKT_C_CHAT = 2,
		PKT_S_CHAT = 3,
		PKT_C_SPAWN = 4,
		PKT_S_SPAWN = 5,
		PKT_S_MONSTERSPAWN = 6,
		PKT_C_LEAVE_GAME = 7,
		PKT_S_DESPAWN = 8,
		PKT_C_MOVE = 9,
		PKT_S_MOVE = 10,
		PKT_C_ATTACK = 11,
		PKT_S_ATTACK = 12,
		PKT_S_DIE = 13,
	};

	// Custom Handlers
	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);
	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt);
	bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt);
	bool Handle_C_SPAWN(PacketSessionRef& session, Protocol::C_SPAWN& pkt);
	bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt);
	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt);
	bool Handle_C_ATTACK(PacketSessionRef& session, Protocol::C_ATTACK& pkt);

	class ClientPacketHandler
	{
	public:
		static void Init()
		{
			for (int32 i = 0; i < UINT16_MAX; i++)
				GPacketHandler[i] = Handle_INVALID;
			GPacketHandler[PKT_C_ENTER_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_ENTER_GAME > (Handle_C_ENTER_GAME, session, buffer, len); };
			GPacketHandler[PKT_C_CHAT] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_CHAT > (Handle_C_CHAT, session, buffer, len); };
			GPacketHandler[PKT_C_SPAWN] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_SPAWN > (Handle_C_SPAWN, session, buffer, len); };
			GPacketHandler[PKT_C_LEAVE_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_LEAVE_GAME > (Handle_C_LEAVE_GAME, session, buffer, len); };
			GPacketHandler[PKT_C_MOVE] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_MOVE > (Handle_C_MOVE, session, buffer, len); };
			GPacketHandler[PKT_C_ATTACK] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_ATTACK > (Handle_C_ATTACK, session, buffer, len); };
		}

		static bool HandlePacket(PacketSessionRef & session, BYTE * buffer, int32 len)
		{
			PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
			return GPacketHandler[header->id](session, buffer, len);
		}
		static SendBufferRef MakeSendBuffer(Protocol::S_ENTER_GAME&pkt) { return MakeSendBuffer(pkt, PKT_S_ENTER_GAME); }
		static SendBufferRef MakeSendBuffer(Protocol::S_CHAT&pkt) { return MakeSendBuffer(pkt, PKT_S_CHAT); }
		static SendBufferRef MakeSendBuffer(Protocol::S_SPAWN&pkt) { return MakeSendBuffer(pkt, PKT_S_SPAWN); }
		static SendBufferRef MakeSendBuffer(Protocol::S_MONSTERSPAWN&pkt) { return MakeSendBuffer(pkt, PKT_S_MONSTERSPAWN); }
		static SendBufferRef MakeSendBuffer(Protocol::S_DESPAWN&pkt) { return MakeSendBuffer(pkt, PKT_S_DESPAWN); }
		static SendBufferRef MakeSendBuffer(Protocol::S_MOVE&pkt) { return MakeSendBuffer(pkt, PKT_S_MOVE); }
		static SendBufferRef MakeSendBuffer(Protocol::S_ATTACK&pkt) { return MakeSendBuffer(pkt, PKT_S_ATTACK); }
		static SendBufferRef MakeSendBuffer(Protocol::S_DIE&pkt) { return MakeSendBuffer(pkt, PKT_S_DIE); }

	private:
		template<typename PacketType, typename ProcessFunc>
		static bool HandlePacket(ProcessFunc func, PacketSessionRef & session, BYTE * buffer, int32 len)
		{
			PacketType pkt;
			if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
				return false;

			return func(session, pkt);
		}

		template<typename T>
		static SendBufferRef MakeSendBuffer(T & pkt, uint16 pktId)
		{
			const uint16 dataSize = static_cast<uint16>(pkt.ByteSizeLong());
			const uint16 packetSize = dataSize + sizeof(PacketHeader);

			SendBufferRef sendBuffer = GSendBufferManager->Open(packetSize);
			PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBuffer->Buffer());
			header->size = packetSize;
			header->id = pktId;
			ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
			sendBuffer->Close(packetSize);

			return sendBuffer;
		}
	};
}