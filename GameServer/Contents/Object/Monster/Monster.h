#pragma once

#include "../GameObject.h"

namespace FrokEngine
{
	class Monster :
		public GameObject
	{
	public:
		Monster();
		virtual ~Monster();

		void MoveTo(class Player& target);
		void HitPlayer(class Player& target);
		void Damaged(float damage);
		bool IsAlive();
		bool IsAttacking();
		bool IsPlayerInTraceRange(class Player& target);
		bool IsPlayerInHitRange(class Player& target);
		void SetLocation(float x, float y, float z);

		float	X;				// X좌표
		float	Y;				// Y좌표
		float	Z;				// Z좌표
		float	Health;			// 체력
		int		Id;				// 고유 id
		float	TraceRange;		// 추격 범위
		float	HitRange;		// 타격 범위
		float	MovePoint;		// 이동 포인트
		float	HitPoint;		// 타격 포인트	
		bool	bIsAttacking;	// 공격중인지	

	private:
		bool	bIsTracking;	// 추격중인지
	};

	class MonsterManager
	{
	public:
		map<int, Monster> monsters;
	};
}
