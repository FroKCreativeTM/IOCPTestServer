#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "BufferReader.h"
#include "ServerPacketHandler.h"

char sendData[] = "Hello World";

class ServerSession : public PacketSession
{

	~ServerSession()
	{
		cout << "~ServerSession" << endl;
	}

	virtual void OnConnected() override
	{
		Protocol::C_ENTER_GAME pkt;
		auto sendBuffer = ServerPacketHandler::MakeSendBuffer(pkt);
		Send(sendBuffer);
	}

	virtual void OnRecvPacket(BYTE* buffer, int32 len) override
	{
		PacketSessionRef session = GetPacketSessionRef();
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);

		// TODO : packetId 대역 체크
		ServerPacketHandler::HandlePacket(session, buffer, len);
	}

	virtual void OnSend(int32 len) override
	{
		//cout << "OnSend Len = " << len << endl;
	}

	virtual void OnDisconnected() override
	{
		//cout << "Disconnected" << endl;
		Protocol::C_LEAVE_GAME pkt;
		auto sendBuffer = ServerPacketHandler::MakeSendBuffer(pkt);
		Send(sendBuffer);
	}
};

int main(int argc, char** argv)
{
	string IP;
	int32 port;

	// 테스트 상황에만 이렇게 합니다.
	if (argc != 2)
	{
		IP = "127.0.0.1";
		port = 7777;
	}
	else
	{
		IP = string(argv[0]);
		port = atoi(argv[1]);
	}

	wstring wIP;
	wIP.assign(IP.begin(), IP.end());

	ServerPacketHandler::Init();

	this_thread::sleep_for(1s);

	cout << "[Server INFO]" << endl;
	wcout << L"IP : " << wIP << endl;
	cout << "port : " << port << endl;
	ClientServiceRef service = MakeShared<ClientService>(
		NetAddress(wIP.c_str(), port),
		MakeShared<IocpCore>(),
		MakeShared<ServerSession>, // TODO : SessionManager 등
		1);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 2; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					service->GetIocpCore()->Dispatch(0);
				}
			});
	}

	GThreadManager->Join();
}