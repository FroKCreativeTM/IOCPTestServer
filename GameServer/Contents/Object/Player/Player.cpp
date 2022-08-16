#include "../../../pch.h"
#include "Player.h"

namespace FrokEngine
{
	Player::Player()
	{
		creatureState = Protocol::CreatureState::IDLE;
		gameObjectType = Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER;

		// TODO : 레벨 데이터 테이블을 읽어서 거기서 데이터를 들고올 수 있게 변경한다.
		statInfo.set_level(1);
		
		statInfo.set_hp(20.f);
		statInfo.set_mp(10.f);

		statInfo.set_maxhp(20.f);
		statInfo.set_maxmp(10.f);

		statInfo.set_exp(0.0f);
		statInfo.set_totalexp(100.0f);

		statInfo.set_attack(10.f);
	}
	bool Player::IsPlayerInHitRange(PlayerRef target)
	{
		return false;
	}
	bool Player::IsMonsterInHitRange(MonsterRef target)
	{
		return false;
	}
}

