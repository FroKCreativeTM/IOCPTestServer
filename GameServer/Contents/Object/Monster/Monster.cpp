#include "../../../pch.h"

#include <ThreadManager.h>
#include <ConsoleLog.h>
#include "Monster.h"
#include "../Player/Player.h"

#include "../../../ClientPacketHandler.h"
#include "../../../GameRoom.h"


namespace FrokEngine
{
	Monster::Monster()
		: movePoint(5), hitPoint(0.1f),
		traceRange(350), hitRange(180),
		isAttack(false),
		isTracing(false)
	{
		objectInfo.mutable_posinfo()->set_posx(0);
		objectInfo.mutable_posinfo()->set_posy(0);
		objectInfo.mutable_posinfo()->set_posz(0);

		stat.set_hp(0);
	}

	Monster::~Monster()
	{
	}

	void Monster::MoveTo(PlayerRef target)
	{
		auto targetPos = target->objectInfo.posinfo();
		auto monsterPos = objectInfo.posinfo();

		if (targetPos.posx() > monsterPos.posx())
			objectInfo.mutable_posinfo()->set_posx(monsterPos.posx() + movePoint);
		if (targetPos.posx() < monsterPos.posx())
			objectInfo.mutable_posinfo()->set_posx(monsterPos.posx() - movePoint);
		if (targetPos.posy() > monsterPos.posy())
			objectInfo.mutable_posinfo()->set_posy(monsterPos.posy() + movePoint);
		if (targetPos.posy() < monsterPos.posy())
			objectInfo.mutable_posinfo()->set_posy(monsterPos.posy() - movePoint);
		if (targetPos.posz() > monsterPos.posz())
			objectInfo.mutable_posinfo()->set_posz(monsterPos.posz() + movePoint);
		if (targetPos.posz() < monsterPos.posz())
			objectInfo.mutable_posinfo()->set_posz(monsterPos.posz() - movePoint);

		GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"[Monster ID : %d, X : %f / Y : %f / Z : %f\n]", 
			objectInfo.objectid(),
			monsterPos.posx(), monsterPos.posy(), monsterPos.posz());
	}

	void Monster::HitPlayer(PlayerRef target)
	{
		std::thread t([&]() {
			// 1초에 한번씩 때리도록		
			isAttack = true;
			target->objectInfo.mutable_statinfo()->set_hp(target->objectInfo.statinfo().hp() - hitPoint);
			GConsoleLogger->WriteStdOut(FrokEngine::Color::RED, L"플레이어 때림\n");
			GConsoleLogger->WriteStdOut(FrokEngine::Color::RED, L"플레이어 HP : %d\n", target->objectInfo.statinfo().hp());

			Protocol::S_ATTACK attackPkt;
			attackPkt.set_attackerid(this->GetObjectID());
			attackPkt.set_attackertype(Protocol::GameObjectType::GAME_OBJECT_TYPE_MONSTER);

			attackPkt.set_hittedid(target->objectInfo.objectid());
			attackPkt.set_attackertype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);

			attackPkt.set_afterhp(target->objectInfo.statinfo().hp() - hitPoint);

			auto sendBuffer = ClientPacketHandler::MakeSendBuffer(attackPkt);
			GRoom->Broadcast(sendBuffer);

			this_thread::sleep_for(1s);
			isAttack = false;
			});
		t.detach();
	}

	void Monster::Damaged(float damage)
	{
		stat.set_hp(stat.hp() - damage);
		printf_s("맞음 남은 체력 : %f\n", stat.hp());
	}

	bool Monster::IsAlive()
	{
		return stat.hp() > 0;
	}

	bool Monster::IsAttacking()
	{
		return isAttack;
	}

	bool Monster::IsPlayerInTraceRange(PlayerRef target)
	{
		if (abs(target->objectInfo.posinfo().posx() - objectInfo.posinfo().posx()) < traceRange
			&& abs(target->objectInfo.posinfo().posy() - objectInfo.posinfo().posy()) < traceRange)
		{
			GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"PLAYER in Trace Range!~!!\n");
			isTracing = true;
			return true;
		}

		isTracing = false;
		return false;
	}

	bool Monster::IsPlayerInHitRange(PlayerRef target)
	{
		if (abs(target->objectInfo.posinfo().posx() - objectInfo.posinfo().posx()) < hitRange
			&& abs(target->objectInfo.posinfo().posy() - objectInfo.posinfo().posy()) < hitRange)
		{
			GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"PLAYER in Hit Range!~!!\n");
			return true;
		}

		return false;
	}

	int32 Monster::GetObjectID()
	{
		return objectInfo.objectid();
	}

	void Monster::SetObjectID(int32 id)
	{
		objectInfo.set_objectid(id);
	}

	int32 Monster::GetHP()
	{
		return stat.hp();
	}

	void Monster::SetHP(int32 HP)
	{
		stat.set_hp(HP);
	}

	float Monster::GetMovePoint()
	{
		return movePoint;
	}

	void Monster::SetMovePoint(float MovePoint)
	{
		movePoint = MovePoint;
	}

	Protocol::PosInfo Monster::GetPosInfo()
	{
		return objectInfo.posinfo();
	}

	void Monster::SetLocation(float x, float y, float z)
	{
		objectInfo.mutable_posinfo()->set_posx(x);
		objectInfo.mutable_posinfo()->set_posy(y);
		objectInfo.mutable_posinfo()->set_posz(z);
	}
}