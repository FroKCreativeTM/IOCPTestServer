#include "pch.h"
#include "GameObject.h"

namespace FrokEngine
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	int GameObject::GetObjectId() const
	{
		return this->_objectId;
	}
	
	void GameObject::SetObjectId(int id)
	{
		this->_objectId = id;
	}

	Protocol::StatInfo GameObject::GetStat()
	{
		return Protocol::StatInfo();
	}

	void GameObject::SetStat(const Protocol::StatInfo& stat)
	{
	}

	Protocol::PositionInfo GameObject::GetPosInfo()
	{
		return Protocol::PositionInfo();
	}

	void GameObject::SetPosInfo(const Protocol::PositionInfo& posInfo)
	{
	}

	Protocol::GameObjectType GameObject::GetGameObjectType() const
	{
		return Protocol::GameObjectType();
	}

	void GameObject::SetGameObjectType(const Protocol::GameObjectType& objectType)
	{
	}

	Protocol::ObjectInfo GameObject::GetObjectInfo()
	{
		return Protocol::ObjectInfo();
	}

	void GameObject::SetObjectInfo(const Protocol::ObjectInfo& objInfo)
	{
	}

	Protocol::CreatureState GameObject::GetCreatureState() const
	{
		return Protocol::CreatureState();
	}

	void GameObject::SetCreatureState(const Protocol::CreatureState& state)
	{
	}

	float GameObject::GetSpeed() const
	{
		return 0.0f;
	}

	void GameObject::SetSpeed(float speed)
	{
	}

	int32 GameObject::GetHP() const
	{
		return int32();
	}

	void GameObject::SetHP(int32 hp)
	{
	}

	GameSessionRef GameObject::GetOwnerSession()
	{
		return this->_ownerSession;
	}

	void GameObject::SetOwnerSession(GameSessionRef ref)
	{
		this->_ownerSession = ref;
	}

	void GameObject::OnDamaged(GameObjectPtr attacker, int damage)
	{
	}

	void GameObject::OnDead(GameObjectPtr attacker)
	{
	}
}