#pragma once

#include "../GameObject.h"

namespace FrokEngine
{
	class Player : 
		public GameObject
	{
	public:
		// id(토큰으로 대체 예정), character name
		// posInfo, statInfo
		Protocol::ObjectInfo		objectInfo;

		// 애니메이션 상태(이거에 맞춰서 애니메이션을 실행한다.)
		Protocol::CreatureState		creatureState;

		GameSessionRef			ownerSession; // Cycle
	};
}

