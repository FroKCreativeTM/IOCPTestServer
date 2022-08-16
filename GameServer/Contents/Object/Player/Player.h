#pragma once

namespace FrokEngine
{
	class Player 
	{
	public:
		// Protobuf �� �ִ� �������ݰ� ����
		Protocol::GameObjectType	gameObjectType;
		Protocol::PlayerType		playerType;
		Protocol::ObjectInfo		objectInfo;
		Protocol::CreatureState		creatureState;
		Protocol::StatInfo			statInfo;

		GameSessionRef			ownerSession; // Cycle

		Player();
	};
}

