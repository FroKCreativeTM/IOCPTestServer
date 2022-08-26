#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ConsoleLog.h"

#include <DBBind.h>

#include "ClientPacketHandler.h"
#include <tchar.h>
#include "Protocol.pb.h"
#include "Job.h"
#include "GameRoom.h"
#include "Contents/Object/Player/Player.h"
#include "ConfigManager.h"

enum
{
	WORKER_TICK = 64
};

void DoWorkerJob(ServerServiceRef& service)
{
	while (true)
	{
		LEndTickCount = ::GetTickCount64() + WORKER_TICK;

		GRoom->Update();

		// 네트워크 입출력 처리 -> 인게임 로직까지 (패킷 핸들러에 의해)
		service->GetIocpCore()->Dispatch(10);

		// 예약된 일감 처리
		ThreadManager::DistributeReservedJobs();

		// 글로벌 큐
		ThreadManager::DoGlobalQueueWork();
	}
}

// 컨텐츠를 위한 DB와 AccountServer(NodeJS)와 토큰을 주고 받을 DB풀
unique_ptr<DBConnectionPool> GDBConnectionPool = make_unique<DBConnectionPool>();
unique_ptr<DBConnectionPool> GSharedDBConnectionPool = make_unique<DBConnectionPool>();

int main(int argc, char* argv[])
{
	// DB부터 켜자
	// 1번째 인자 : 스레드 수
	// 2번째 인자 : 연결을 위한 DSN 
	// ASSERT_CRASH(GDBConnectionPool->Connect(1, ConfigManager::GetInst()->GetServerConfig().DBConnectionString.c_str()));
	ASSERT_CRASH(GDBConnectionPool->Connect(1, ConfigManager::GetInst()->GetServerConfig().DBConnectionString.c_str()));
	// TODO : SharedDB를 관리하기 위한 풀도!

	GRoom->DoTimer(1000, [] { GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"Hello 1000\n"); });
	GRoom->DoTimer(2000, [] { GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"Hello 2000\n"); });
	GRoom->DoTimer(3000, [] { GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"Hello 3000\n"); });

	ClientPacketHandler::Init();

	string IP;
	int32 port;

	// 테스트 상황에만 이렇게 합니다.
	if (argc < 2)
	{
		IP = "127.0.0.1";
		port = 7777;
	}
	else
	{
		IP = argv[1];
		port = atoi(argv[2]);
	}

	wstring wIP;
	wIP.assign(IP.begin(), IP.end());

	GConsoleLogger->WriteStdOut(FrokEngine::Color::WHITE, L"[Server INFO]\n");
	GConsoleLogger->WriteStdOut(FrokEngine::Color::WHITE, L"[IP : %s]\n", wIP.c_str());
	GConsoleLogger->WriteStdOut(FrokEngine::Color::WHITE, L"[PORT : %d]\n", port);

	// 로그인 서버 포트 번호 : 7776
	// 게임 컨텐츠 서버 포트 번호 : 7777
	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(wIP.c_str(), port),
		MakeShared<IocpCore>(),
		MakeShared<GameSession>, // TODO : SessionManager 등
		100);

	ASSERT_CRASH(service->Start());

	// 4개의 스레드가 컨텐츠를 실행하게 한다.
	for (int32 i = 0; i < 4; i++)
	{
		GThreadManager->Launch([&service]()
			{
				DoWorkerJob(service);
			});
	}

	// Main Thread
	DoWorkerJob(service);

	GThreadManager->Join();
}