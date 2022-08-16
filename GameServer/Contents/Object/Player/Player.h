#pragma once

namespace FrokEngine
{
	class Player 
	{
	public:
		// Protobuf 상에 있는 프로토콜과 통일
		Protocol::GameObjectType	gameObjectType;
		Protocol::PlayerType		playerType;
		Protocol::ObjectInfo		objectInfo;
		Protocol::CreatureState		creatureState;
		Protocol::StatInfo			statInfo;

		GameSessionRef			ownerSession; // Cycle

		Player();
	};
}

