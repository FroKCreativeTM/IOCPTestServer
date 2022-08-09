#include "../../../pch.h"
#include "Monster.h"

namespace FrokEngine
{
	Monster::Monster()
		: X(0), Y(0), Z(-1000),
		Health(0), MovePoint(5), HitPoint(0.1f),
		TraceRange(700), HitRange(180),
		bIsAttacking(false),
		bIsTracking(false)
	{
		X = rand() % 1000;
	}

	Monster::~Monster()
	{
	}

	void Monster::MoveTo()
	{
	}

	void Monster::HitPlayer(Player& target)
	{
	}

	void Monster::Damaged(float damage)
	{
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
		return false;
	}

	bool Monster::IsPlayerInHitRange(Player& target)
	{
		return false;
	}

	void Monster::SetLocation(float x, float y, float z)
	{
	}

}