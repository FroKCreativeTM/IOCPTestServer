#include "pch.h"
#include "ServerPacketHandler.h"

namespace FrokEngine
{
	PacketHandlerFunc GPacketHandler[UINT16_MAX];

	// 직접 컨텐츠 작업자

	bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
	{
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		// TODO : Log
		return false;
	}

	bool Handle_S_LOGIN(PacketSessionRef& session, Protocol::S_LOGIN& pkt)
	{
		if (pkt.players().size() == 0)
		{
			// 캐릭터 생성창
		}

		if (pkt.success()) 
		{
			cout << "로그인 완료" << endl;
		}
		else 
		{
			cout << "로그인 실패" << endl;
		}

		// 입장 UI 버튼 눌러서 게임 입장
		// Protocol::C_ENTER_GAME enterGamePkt;
		// enterGamePkt.set_playerindex(0); // 첫번째 캐릭터로 입장
		// auto sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
		// session->Send(sendBuffer);

		return true;
	}

	// 회원가입 요청 시 성공 여부를 받아낸다..
	bool Handle_S_SIGNUP(PacketSessionRef& session, Protocol::S_SIGNUP& pkt)
	{
		// 성공 시
		if (pkt.success() == 1) {
			cout << "회원가입 성공" << endl;
		}
		else {
			cout << "이미 있는 회원입니다." << endl;
		}

		return true;
	}

	bool Handle_S_ENTER_GAME(PacketSessionRef& session, Protocol::S_ENTER_GAME& pkt)
	{
		// TODO
		return true;
	}

	bool Handle_S_CURRENT_PLAYER_INFO(PacketSessionRef& session, Protocol::S_CURRENT_PLAYER_INFO& pkt)
	{
		return false;
	}

	bool Handle_S_CHAT(PacketSessionRef& session, Protocol::S_CHAT& pkt)
	{
		std::cout << pkt.msg() << endl;
		return true;
	}
	bool Handle_S_MOVE(PacketSessionRef& session, Protocol::S_MOVE& pkt)
	{
		return false;
	}
}