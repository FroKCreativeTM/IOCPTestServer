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
	};

	// Custom Handlers
	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);
	bool Handle_S_ENTER_GAME(PacketSessionRef& session, Protocol::S_ENTER_GAME& pkt);
	bool Handle_S_CHAT(PacketSessionRef& session, Protocol::S_CHAT& pkt);
	bool Handle_S_SPAWN(PacketSessionRef& session, Protocol::S_SPAWN& pkt);
	bool Handle_S_MONSTERSPAWN(PacketSessionRef& session, Protocol::S_MONSTERSPAWN& pkt);
	bool Handle_S_DESPAWN(PacketSessionRef& session, Protocol::S_DESPAWN& pkt);
	bool Handle_S_MOVE(PacketSessionRef& session, Protocol::S_MOVE& pkt);
	bool Handle_S_ATTACK(PacketSessionRef& session, Protocol::S_ATTACK& pkt);

	class ServerPacketHandler
	{
	public:
		static void Init()
		{
			for (int32 i = 0; i < UINT16_MAX; i++)
				GPacketHandler[i] = Handle_INVALID;
			GPacketHandler[PKT_S_ENTER_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_ENTER_GAME > (Handle_S_ENTER_GAME, session, buffer, len); };
			GPacketHandler[PKT_S_CHAT] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_CHAT > (Handle_S_CHAT, session, buffer, len); };
			GPacketHandler[PKT_S_SPAWN] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_SPAWN > (Handle_S_SPAWN, session, buffer, len); };
			GPacketHandler[PKT_S_MONSTERSPAWN] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_MONSTERSPAWN > (Handle_S_MONSTERSPAWN, session, buffer, len); };
			GPacketHandler[PKT_S_DESPAWN] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_DESPAWN > (Handle_S_DESPAWN, session, buffer, len); };
			GPacketHandler[PKT_S_MOVE] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_MOVE > (Handle_S_MOVE, session, buffer, len); };
			GPacketHandler[PKT_S_ATTACK] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::S_ATTACK > (Handle_S_ATTACK, session, buffer, len); };
		}

		static bool HandlePacket(PacketSessionRef & session, BYTE * buffer, int32 len)
		{
			PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
			return GPacketHandler[header->id](session, buffer, len);
		}
		static SendBufferRef MakeSendBuffer(Protocol::C_ENTER_GAME&pkt) { return MakeSendBuffer(pkt, PKT_C_ENTER_GAME); }
		static SendBufferRef MakeSendBuffer(Protocol::C_CHAT&pkt) { return MakeSendBuffer(pkt, PKT_C_CHAT); }
		static SendBufferRef MakeSendBuffer(Protocol::C_SPAWN&pkt) { return MakeSendBuffer(pkt, PKT_C_SPAWN); }
		static SendBufferRef MakeSendBuffer(Protocol::C_LEAVE_GAME&pkt) { return MakeSendBuffer(pkt, PKT_C_LEAVE_GAME); }
		static SendBufferRef MakeSendBuffer(Protocol::C_MOVE&pkt) { return MakeSendBuffer(pkt, PKT_C_MOVE); }
		static SendBufferRef MakeSendBuffer(Protocol::C_ATTACK&pkt) { return MakeSendBuffer(pkt, PKT_C_ATTACK); }

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