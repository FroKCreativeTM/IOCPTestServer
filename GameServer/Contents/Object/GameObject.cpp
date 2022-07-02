#include "pch.h"
#include "GameObject.h"

namespace FrokEngine
{
	int GameObject::GetObjectId() const
	{
		return this->_objectId;
	}
	
	void GameObject::SetObjectId(int id)
	{
		this->_objectId = id;
	}

	GameSessionRef GameObject::GetOwnerSession()
	{
		return this->_ownerSession;
	}

	void GameObject::SetOwnerSession(GameSessionRef ref)
	{
		this->_ownerSession = ref;
	}
}