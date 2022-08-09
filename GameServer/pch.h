#pragma once

#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#ifdef _DEBUG
#pragma comment(lib, "ServerCore\\Debug\\ServerCore.lib")
#pragma comment(lib, "ServerCore\\Debug\\DBCore.lib")
#pragma comment(lib, "Protobuf\\Debug\\libprotobufd.lib")
#else
#pragma comment(lib, "ServerCore\\Release\\ServerCore.lib")
#pragma comment(lib, "ServerCore\\Release\\DBCore.lib")
#pragma comment(lib, "Protobuf\\Release\\libprotobuf.lib")
#endif

#if _MSC_VER >= 1932 // Visual Studio 2022 version 17.2+
#    pragma comment(linker, "/alternatename:__imp___std_init_once_complete=__imp_InitOnceComplete")
#    pragma comment(linker, "/alternatename:__imp___std_init_once_begin_initialize=__imp_InitOnceBeginInitialize")
#endif

#include "CorePch.h"

#include <DBConnection.h>
#include <DBConnectionPool.h>	// DB의 연결을 총괄하는 Pool 매니저 클래스

#include "Protocol.pb.h"
#include "Enum.pb.h"
#include "Struct.pb.h"

using namespace FrokEngine;

namespace FrokEngine
{
	using GameSessionRef = shared_ptr<class GameSession>;
	using GameObjectRef = shared_ptr<class GameObject>;
	using PlayerRef = shared_ptr<class Player>;
	using MonsterRef = shared_ptr<class Monster>;
	using SeranaRef = shared_ptr<class Serana>;
	using LukeRef = shared_ptr<class Luke>;
}