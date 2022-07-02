#pragma once

namespace FrokEngine 
{
	class GameObject
	{
	public : 
		int GetObjectId() const;
		void SetObjectId(int id);

		GameSessionRef GetOwnerSession();
		void SetOwnerSession(GameSessionRef ref);

	protected : 
		int _objectId;
		GameSessionRef			_ownerSession; // Cycle

		Protocol::GameObjectType _objectType = Protocol::GameObjectType::GAME_OBJECT_TYPE_NONE;
		// Protocol::PosInfo
	};
}

