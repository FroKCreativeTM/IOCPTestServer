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

		float	X;				// X��ǥ
		float	Y;				// Y��ǥ
		float	Z;				// Z��ǥ
		float	Health;			// ü��
		int		Id;				// ���� id
		float	TraceRange;		// �߰� ����
		float	HitRange;		// Ÿ�� ����
		float	MovePoint;		// �̵� ����Ʈ
		float	HitPoint;		// Ÿ�� ����Ʈ	
		bool	bIsAttacking;	// ����������	

	private:
		bool	bIsTracking;	// �߰�������
	};

	class MonsterManager
	{
	public:
		map<int, Monster> monsters;
	};
}
