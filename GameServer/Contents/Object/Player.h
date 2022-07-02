#pragma once

#include "GameObject.h"

namespace FrokEngine
{
	class Player : public GameObject
	{
	public:
		uint64					playerId = 0;
		string					name;
		string					id;
		Protocol::PosInfo		pos;
		GameSessionRef			ownerSession; // Cycle
	};
}

