#pragma once

#include "../GameObject.h"

namespace FrokEngine
{
	class Player : 
		public GameObject
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

