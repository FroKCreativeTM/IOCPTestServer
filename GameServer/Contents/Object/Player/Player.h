#pragma once

namespace FrokEngine
{
	class Player 
	{
	public : 
		Player();

		bool IsPlayerInHitRange(PlayerRef target);
		bool IsMonsterInHitRange(MonsterRef target);

	public:
		// Protobuf �� �ִ� �������ݰ� ����
		Protocol::GameObjectType	gameObjectType;
		Protocol::PlayerType		playerType;
		Protocol::ObjectInfo		objectInfo;
		Protocol::CreatureState		creatureState;
		Protocol::StatInfo			statInfo;

		GameSessionRef			ownerSession; // Cycle
	};
}

