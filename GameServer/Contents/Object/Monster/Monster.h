#pragma once

namespace FrokEngine
{
	class Monster 
	{
	public:
		Monster();
		virtual ~Monster();

		void MoveTo(PlayerRef target);
		void HitPlayer(PlayerRef target);
		void Damaged(float damage);
		bool IsAlive();
		bool IsAttacking();
		bool IsPlayerInTraceRange(PlayerRef target);
		bool IsPlayerInHitRange(PlayerRef target);

	public : 
		int32 GetObjectID();
		void SetObjectID(int32 id);

		int32 GetHP();
		void SetHP(int32 HP);

		float GetMovePoint();
		void SetMovePoint(float MovePoint);

		Protocol::PosInfo GetPosInfo();
		void SetLocation(float x, float y, float z);

	private : 
		Protocol::GameObjectType gameObjectType = Protocol::GameObjectType::GAME_OBJECT_TYPE_MONSTER;
		Protocol::ObjectInfo objectInfo;
		Protocol::CreatureState state;
		Protocol::StatInfo stat;

		float movePoint;
		float hitPoint;
		int32 traceRange;
		int32 hitRange;
		bool isAttack;
		bool isTracing;

	private:
		bool	bIsTracking;	// 추격중인지
	};

	class MonsterManager
	{
	public:
		map<int, Monster> monsters;
	};
}
