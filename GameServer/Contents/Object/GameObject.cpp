#include "../../pch.h"
#include "GameObject.h"

#include "../../GameSession.h"
#include "../../GameSessionManager.h"
#include "../../ClientPacketHandler.h"

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
		return _statInfo;
	}

	void GameObject::SetStat(const Protocol::StatInfo& stat)
	{
		_statInfo = stat;
	}

	Protocol::GameObjectType GameObject::GetGameObjectType() const
	{
		return _objectType;
	}

	void GameObject::SetGameObjectType(const Protocol::GameObjectType& objectType)
	{
		_objectType = objectType;
	}

	Protocol::ObjectInfo GameObject::GetObjectInfo()
	{
		return _objectInfo;
	}

	void GameObject::SetObjectInfo(const Protocol::ObjectInfo& objInfo)
	{
		_objectInfo = objInfo;
	}

	Protocol::CreatureState GameObject::GetCreatureState() const
	{
		return _state;
	}

	void GameObject::SetCreatureState(const Protocol::CreatureState& state)
	{
		_state = state;
	}

	float GameObject::GetSpeed() const
	{
		return _speed;
	}

	void GameObject::SetSpeed(float speed)
	{
		_speed = speed;
	}

	int32 GameObject::GetHP() const
	{
		return _hp;
	}

	void GameObject::SetHP(int32 hp)
	{
		_hp = hp;
	}

	GameSessionRef GameObject::GetOwnerSession()
	{
		return this->_ownerSession;
	}

	void GameObject::SetOwnerSession(GameSessionRef ref)
	{
		this->_ownerSession = ref;
	}

	void GameObject::OnDamaged(GameObjectRef attacker, int damage)
	{

	}

	void GameObject::OnDead(GameObjectRef attacker)
	{
	}
}