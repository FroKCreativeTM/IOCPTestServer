#include "pch.h"
#include "ThreadManager.h"
#include "Service.h"
#include "Session.h"
#include "GameSession.h"
#include "GameSessionManager.h"
#include "BufferWriter.h"
#include "ClientPacketHandler.h"
#include <tchar.h>
#include "Protocol.pb.h"
#include "Job.h"
#include "GameRoom.h"
#include "Contents/Object/Player.h"

#include <DBBind.h>
#include <Timer.h>

enum
{
	WORKER_TICK = 64
};

void DoWorkerJob(ServerServiceRef& service)
{
	while (true)
	{
		LEndTickCount = ::GetTickCount64() + WORKER_TICK;

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

int main()
{
	// DB부터 켜자
	// 1번째 인자 : 스레드 수
	// 2번째 인자 : 연결을 위한 DSN 
	// ASSERT_CRASH(GDBConnectionPool->Connect(1, ConfigManager::GetInst()->GetServerConfig().dbConnectionString.c_str()));
	// TODO : SharedDB를 관리하기 위한 풀도!

	GRoom->DoTimer(1000, [] { cout << "Hello 1000" << endl; });
	GRoom->DoTimer(2000, [] { cout << "Hello 2000" << endl; });
	GRoom->DoTimer(3000, [] { cout << "Hello 3000" << endl; });

	ClientPacketHandler::Init();

	// 로그인 서버 포트 번호 : 7776
	// 게임 컨텐츠 서버 포트 번호 : 7777
	ServerServiceRef service = MakeShared<ServerService>(
		NetAddress(L"127.0.0.1", 7777),
		MakeShared<IocpCore>(),
		MakeShared<GameSession>, // TODO : SessionManager 등
		100);

	ASSERT_CRASH(service->Start());

	for (int32 i = 0; i < 5; i++)
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