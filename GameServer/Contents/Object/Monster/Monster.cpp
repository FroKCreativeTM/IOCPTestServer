#include "../../../pch.h"

#include <ConsoleLog.h>
#include "Monster.h"
#include "../Player/Player.h"

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
		isAttack = true;
		target->objectInfo.mutable_statinfo()->set_hp(target->objectInfo.statinfo().hp() - hitPoint);
		GConsoleLogger->WriteStdOut(FrokEngine::Color::RED, L"�÷��̾� ����\n");
		GConsoleLogger->WriteStdOut(FrokEngine::Color::RED, L"�÷��̾� HP : %d\n", target->objectInfo.statinfo().hp());
		// 1�ʿ� �ѹ��� ��������		
		std::this_thread::sleep_for(1s);
		isAttack = false;
	}

	void Monster::Damaged(float damage)
	{
		stat.set_hp(stat.hp() - damage);
		printf_s("���� ���� ü�� : %f\n", stat.hp());
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
			return true;

		return false;
	}

	bool Monster::IsPlayerInHitRange(PlayerRef target)
	{
		if (abs(target->objectInfo.posinfo().posx() - objectInfo.posinfo().posx()) < hitRange
			&& abs(target->objectInfo.posinfo().posy() - objectInfo.posinfo().posy()) < hitRange)
		{
			GConsoleLogger->WriteStdOut(FrokEngine::Color::YELLOW, L"FIND PLAYER!~!!\n");
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