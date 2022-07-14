#pragma once

namespace FrokEngine
{
	class Player
	{
	public:
		uint64					playerId = 0;
		string					name;
		Protocol::PosInfo		pos;
		GameSessionRef			ownerSession; // Cycle
	};
}

