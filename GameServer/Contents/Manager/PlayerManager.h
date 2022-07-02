#pragma once

namespace FrokEngine
{
	class PlayerManager
	{

	private:
		USE_LOCK;
		std::map<int, class Player> _players;
	};
}
