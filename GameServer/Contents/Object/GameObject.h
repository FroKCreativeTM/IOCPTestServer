#pragma once

namespace FrokEngine 
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	public:
		int GetObjectId() const;
		void SetObjectId(int id);

		Protocol::StatInfo GetStat();
		void SetStat(const Protocol::StatInfo& stat);

		Protocol::GameObjectType GetGameObjectType() const;
		void SetGameObjectType(const Protocol::GameObjectType& objectType);

		Protocol::ObjectInfo GetObjectInfo();
		void SetObjectInfo(const Protocol::ObjectInfo& objInfo);

		Protocol::CreatureState GetCreatureState() const;
		void SetCreatureState(const Protocol::CreatureState& state);

		float GetSpeed() const;
		void SetSpeed(float speed);

		int32 GetHP() const;
		void SetHP(int32 hp);

		GameSessionRef GetOwnerSession();
		void SetOwnerSession(GameSessionRef ref);

		virtual void OnDamaged(GameObjectRef attacker, int damage);
		virtual void OnDead(GameObjectRef attacker);

	protected : 
		int _objectId;

		// 오브젝트에 대한 정보가 담겨있음
		Protocol::ObjectInfo			_objectInfo;
		Protocol::StatInfo				_statInfo;
		Protocol::GameObjectType		_objectType = Protocol::GameObjectType::GAME_OBJECT_TYPE_NONE;

		float							_speed;
		int32							_hp;
		Protocol::CreatureState			_state;

		GameSessionRef			_ownerSession; // Cycle
	};
}

