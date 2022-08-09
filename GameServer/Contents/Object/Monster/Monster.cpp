#include "../../../pch.h"
#include "Monster.h"
#include "../Player/Player.h"

namespace FrokEngine
{
	Monster::Monster()
		: X(0), Y(0), Z(-1000),
		Health(0), MovePoint(5), HitPoint(0.1f),
		TraceRange(700), HitRange(180),
		bIsAttacking(false),
		bIsTracking(false)
	{
	}

	Monster::~Monster()
	{
	}

	void Monster::MoveTo(Player& target)
	{
		if (target.objectInfo.posinfo().posx() > X)
			X += MovePoint;
		if (target.objectInfo.posinfo().posx() < X)
			X -= MovePoint;
		if (target.objectInfo.posinfo().posy() > Y)
			Y += MovePoint;
		if (target.objectInfo.posinfo().posy() < Y)
			Y -= MovePoint;
		if (target.objectInfo.posinfo().posz() > Z)
			Z += MovePoint;
		if (target.objectInfo.posinfo().posz() < Z)
			Z -= MovePoint;
	}

	void Monster::HitPlayer(Player& target)
	{
		std::thread t([&]() {
			// 1�ʿ� �ѹ��� ��������		
			bIsAttacking = true;
			printf_s("����\n");
			target.objectInfo.mutable_statinfo()->set_hp(target.objectInfo.statinfo().hp() - HitPoint);
			std::this_thread::sleep_for(1s);
			bIsAttacking = false;
			});
		t.detach();
	}

	void Monster::Damaged(float damage)
	{
		Health -= damage;
		printf_s("���� ���� ü�� : %f\n", Health);
	}

	bool Monster::IsAlive()
	{
		return Health > 0;
	}

	bool Monster::IsAttacking()
	{
		return bIsAttacking;
	}

	bool Monster::IsPlayerInTraceRange(Player& target)
	{
		if (abs(target.objectInfo.posinfo().posx() - X) < TraceRange 
			&& abs(target.objectInfo.posinfo().posy() - Y) < TraceRange)
			return true;

		return false;
	}

	bool Monster::IsPlayerInHitRange(Player& target)
	{
		if (abs(target.objectInfo.posinfo().posx() - X) < HitRange 
			&& abs(target.objectInfo.posinfo().posy() - Y) < HitRange)
			return true;

		return false;
	}

	void Monster::SetLocation(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}
}