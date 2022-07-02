#pragma once
#include "Protocol.pb.h"

namespace FrokEngine
{
	using PacketHandlerFunc = std::function<bool(PacketSessionRef&, BYTE*, int32)>;
	extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

	enum : uint16
	{
		PKT_C_LOGIN = 0,
		PKT_S_LOGIN = 1,
		PKT_C_SIGNUP = 2,
		PKT_S_SIGNUP = 3,
		PKT_C_ENTER_GAME = 4,
		PKT_S_ENTER_GAME = 5,
		PKT_C_CURRENT_PLAYER_INFO = 6,
		PKT_S_CURRENT_PLAYER_INFO = 7,
		PKT_C_CHAT = 8,
		PKT_S_CHAT = 9,
		PKT_C_MOVE = 10,
		PKT_S_MOVE = 11,
	};

	// Custom Handlers
	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len);
	bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt);
	bool Handle_C_SIGNUP(PacketSessionRef& session, Protocol::C_SIGNUP& pkt);
	bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt);
	bool Handle_C_CURRENT_PLAYER_INFO(PacketSessionRef& session, Protocol::C_CURRENT_PLAYER_INFO& pkt);
	bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt);
	bool Handle_C_MOVE(PacketSessionRef& session, Protocol::C_MOVE& pkt);

	class ClientPacketHandler
	{
	public:
		static void Init()
		{
			for (int32 i = 0; i < UINT16_MAX; i++)
				GPacketHandler[i] = Handle_INVALID;
			GPacketHandler[PKT_C_LOGIN] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_LOGIN > (Handle_C_LOGIN, session, buffer, len); };
			GPacketHandler[PKT_C_SIGNUP] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_SIGNUP > (Handle_C_SIGNUP, session, buffer, len); };
			GPacketHandler[PKT_C_ENTER_GAME] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_ENTER_GAME > (Handle_C_ENTER_GAME, session, buffer, len); };
			GPacketHandler[PKT_C_CURRENT_PLAYER_INFO] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_CURRENT_PLAYER_INFO > (Handle_C_CURRENT_PLAYER_INFO, session, buffer, len); };
			GPacketHandler[PKT_C_CHAT] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_CHAT > (Handle_C_CHAT, session, buffer, len); };
			GPacketHandler[PKT_C_MOVE] = [](PacketSessionRef& session, BYTE* buffer, int32 len) { return HandlePacket < Protocol::C_MOVE > (Handle_C_MOVE, session, buffer, len); };
		}

		static bool HandlePacket(PacketSessionRef & session, BYTE * buffer, int32 len)
		{
			PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
			return GPacketHandler[header->id](session, buffer, len);
		}
		static SendBufferRef MakeSendBuffer(Protocol::S_LOGIN&pkt) { return MakeSendBuffer(pkt, PKT_S_LOGIN); }
		static SendBufferRef MakeSendBuffer(Protocol::S_SIGNUP&pkt) { return MakeSendBuffer(pkt, PKT_S_SIGNUP); }
		static SendBufferRef MakeSendBuffer(Protocol::S_ENTER_GAME&pkt) { return MakeSendBuffer(pkt, PKT_S_ENTER_GAME); }
		static SendBufferRef MakeSendBuffer(Protocol::S_CURRENT_PLAYER_INFO&pkt) { return MakeSendBuffer(pkt, PKT_S_CURRENT_PLAYER_INFO); }
		static SendBufferRef MakeSendBuffer(Protocol::S_CHAT&pkt) { return MakeSendBuffer(pkt, PKT_S_CHAT); }
		static SendBufferRef MakeSendBuffer(Protocol::S_MOVE&pkt) { return MakeSendBuffer(pkt, PKT_S_MOVE); }

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