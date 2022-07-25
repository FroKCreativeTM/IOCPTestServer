#pragma once

namespace FrokEngine
{
	class Player
	{
	public:
		// id(��ū���� ��ü ����), character name
		// posInfo, statInfo
		Protocol::ObjectInfo		objectInfo;

		// �ִϸ��̼� ����(�̰ſ� ���缭 �ִϸ��̼��� �����Ѵ�.)
		Protocol::CreatureState		creatureState;

		GameSessionRef			ownerSession; // Cycle
	};
}

