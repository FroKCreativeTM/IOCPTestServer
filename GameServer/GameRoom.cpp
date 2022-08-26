#include "pch.h"

#include "ConsoleLog.h"

#include "GameRoom.h"
#include "Contents/Object/Player/Player.h"
#include "Contents/Object/Monster/Monster.h"
#include "GameSession.h"

#include "ClientPacketHandler.h"

namespace FrokEngine
{
	shared_ptr<GameRoom> GRoom = make_shared<GameRoom>();

	void GameRoom::Enter(PlayerRef player)
	{
		if (player == nullptr) return;

		// 이미 내 id값과 비슷한 사람이 있다면? 
		// 이상상황!
		if (_players.find(player->objectInfo.objectid()) != _players.end()) return;

		_players[player->objectInfo.objectid()] = player;

		cout << "Player Entered ID : " << player->objectInfo.objectid() << endl;
		// TODO : DB에서 이미 가입했었던 플레이어인 경우 이 데이터를 가져온다.
		// GDBConnector->Select("Select from character[level, hp, mp, exp] where id == player.id");
		// 즉 원래는 C_ENTER_GAME으로 접속하는 플레이어에 대한 id값만 보내는 식인 것
		{
			Protocol::S_ENTER_GAME enterGamePkt;

			enterGamePkt.mutable_player()->set_gameobjecttype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);
			auto mutPlayer = enterGamePkt.mutable_player();
			mutPlayer->mutable_objectinfo()->set_objectid(static_cast<int32>(player->objectInfo.objectid()));

			// 플레이어의 생성자가 만들어낸 데이터도 같이 보낸다.
			auto stat = mutPlayer->mutable_stat();
			stat->set_level(player->statInfo.level());

			stat->set_hp(player->statInfo.hp());
			stat->set_mp(player->statInfo.mp());

			stat->set_maxhp(player->statInfo.maxhp());
			stat->set_maxmp(player->statInfo.maxmp());

			stat->set_exp(player->statInfo.exp());
			stat->set_totalexp(player->statInfo.totalexp());

			stat->set_attack(player->statInfo.attack());

			auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
			player->ownerSession->Send(sendBuffer);
		}

		SendOtherPlayerDataToPlayer(player);
		SendEnterPlayerDataToOther(player);
		SendFieldMonstersDataToPlayer(player);
	}

	void GameRoom::Leave(PlayerRef player)
	{
		// 요청한 NetworkID 값을 가진 사람이 없다면?
		// 이상상황!
		if (_players.find(player->objectInfo.objectid()) == _players.end()) return;

		// TODO : DB에 방금 퇴장한 유저의 데이터를 저장한다.
		// GDBConnector->Update("Update character set [level, hp, mp, exp] where id == player.id");

		_players.erase(player->objectInfo.objectid());

		cout << "Player Leaved ID : " << player->objectInfo.objectid() << endl;

		SendLeavePlayerDataToOther(player);
	}

	void GameRoom::Broadcast(SendBufferRef sendBuffer)
	{
		for (auto& p : _players)
		{
			p.second->ownerSession->Send(sendBuffer);
		}
	}

	void GameRoom::SetPlayerPos(uint64 networkID, Protocol::PosInfo posInfo, Protocol::CreatureState animState)
	{
		// 요청한 NetworkID 값을 가진 사람이 없다면?
		// 이상상황!
		if (_players.find(networkID) == _players.end()) return;

		_players[networkID]->objectInfo.mutable_posinfo()->set_posx(posInfo.posx());
		_players[networkID]->objectInfo.mutable_posinfo()->set_posy(posInfo.posy());
		_players[networkID]->objectInfo.mutable_posinfo()->set_posz(posInfo.posz());

		_players[networkID]->objectInfo.mutable_posinfo()->set_yaw(posInfo.yaw());
		_players[networkID]->objectInfo.mutable_posinfo()->set_roll(posInfo.roll());
		_players[networkID]->objectInfo.mutable_posinfo()->set_pitch(posInfo.pitch());

		_players[networkID]->objectInfo.mutable_posinfo()->set_velox(posInfo.velox());
		_players[networkID]->objectInfo.mutable_posinfo()->set_veloy(posInfo.veloy());
		_players[networkID]->objectInfo.mutable_posinfo()->set_veloz(posInfo.veloz());

		_players[networkID]->objectInfo.mutable_posinfo()->set_speed(posInfo.speed());
		_players[networkID]->objectInfo.mutable_posinfo()->set_isinair(posInfo.isinair());

		Protocol::S_MOVE movePacket;

		movePacket.set_playerid(networkID);

		// 스폰하는 캐릭터에 대한 정보를 보낸다.
		movePacket.set_creaturestate(animState);

		auto myPosInfo = movePacket.mutable_posinfo();
		myPosInfo->set_posx(posInfo.posx());
		myPosInfo->set_posy(posInfo.posy());
		myPosInfo->set_posz(posInfo.posz());

		myPosInfo->set_yaw(posInfo.yaw());
		myPosInfo->set_pitch(posInfo.pitch());
		myPosInfo->set_roll(posInfo.roll());

		myPosInfo->set_velox(posInfo.velox());
		myPosInfo->set_veloy(posInfo.veloy());
		myPosInfo->set_veloz(posInfo.veloz());

		myPosInfo->set_speed(posInfo.speed());
		myPosInfo->set_isinair(posInfo.isinair());

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(movePacket);

		// 다른 사람들에게도 보내준다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != networkID)
			{
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::Attack(Protocol::C_ATTACK& attackPkt)
	{
		// 공격에 관련된 정보를 다룬다.
		
		// 몬스터의 공격은 서버에서 다루고 있는 주제이기 때문에
		// 여기서는 플레이어의 공격을 다룬다.
		auto attacker = _players[attackPkt.attackerid()];

		Protocol::S_ATTACK attackPacket;
		attackPacket.set_attackerid(attackPkt.attackerid());
		attackPacket.set_attackertype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);

		// 피격 대상이 몬스터인지 플레이어인지 파악한다.
		if (attackPkt.hittedtype() == Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER)
		{	// 플레이어가 피격당한 경우
			auto hitted = _players[attackPkt.hittedid()];
			hitted->objectInfo.mutable_statinfo()->set_hp(hitted->objectInfo.statinfo().hp() - attacker->statInfo.attack());

			attackPacket.set_hittedid(attackPkt.hittedid());
			attackPacket.set_hittedtype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);
			attackPacket.set_afterhp(hitted->objectInfo.statinfo().hp() - attacker->statInfo.attack());
		}
		else
		{	// 몬스터가 피격당한 경우
			auto hitted = _monsters[attackPkt.hittedid()];
			hitted->SetHP(hitted->GetHP() - attacker->statInfo.attack());

			attackPacket.set_hittedid(attackPkt.hittedid());
			attackPacket.set_hittedtype(Protocol::GameObjectType::GAME_OBJECT_TYPE_MONSTER);
			attackPacket.set_afterhp(hitted->GetHP() - attacker->statInfo.attack());
		}

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(attackPacket);
		Broadcast(sendBuffer);
	}

	void GameRoom::SendOtherPlayerDataToPlayer(PlayerRef player)
	{
		// 지금 이미 입장한 사람들에 대한 정보를 지금 접속한 플레이어한테 보낸다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.mutable_player()->mutable_objectinfo()->set_objectid(otherPlayer.second->objectInfo.objectid());
				spawnGamePkt.mutable_player()->set_gameobjecttype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);

				// 지금 접속중인 플레이어들의 스텟을 보낸다.
				auto stat = spawnGamePkt.mutable_player()->mutable_stat();
				stat->set_level(otherPlayer.second->statInfo.level());

				stat->set_hp(otherPlayer.second->statInfo.hp());
				stat->set_mp(otherPlayer.second->statInfo.mp());

				stat->set_maxhp(otherPlayer.second->statInfo.maxhp());
				stat->set_maxmp(otherPlayer.second->statInfo.maxmp());

				stat->set_exp(otherPlayer.second->statInfo.exp());
				stat->set_totalexp(otherPlayer.second->statInfo.totalexp());

				stat->set_attack(otherPlayer.second->statInfo.attack());

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_player()->mutable_objectinfo()->mutable_posinfo();
				posInfo->set_posx(otherPlayer.second->objectInfo.mutable_posinfo()->posx());
				posInfo->set_posy(otherPlayer.second->objectInfo.mutable_posinfo()->posy());
				posInfo->set_posz(otherPlayer.second->objectInfo.mutable_posinfo()->posz());

				posInfo->set_yaw(otherPlayer.second->objectInfo.mutable_posinfo()->yaw());
				posInfo->set_pitch(otherPlayer.second->objectInfo.mutable_posinfo()->pitch());
				posInfo->set_roll(otherPlayer.second->objectInfo.mutable_posinfo()->roll());

				posInfo->set_velox(otherPlayer.second->objectInfo.mutable_posinfo()->velox());
				posInfo->set_veloy(otherPlayer.second->objectInfo.mutable_posinfo()->veloy());
				posInfo->set_veloz(otherPlayer.second->objectInfo.mutable_posinfo()->veloz());

				posInfo->set_speed(otherPlayer.second->objectInfo.mutable_posinfo()->speed());
				posInfo->set_isinair(otherPlayer.second->objectInfo.mutable_posinfo()->isinair());

				auto sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				player->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::SendEnterPlayerDataToOther(PlayerRef player)
	{
		// 내가 접속했다는 사실을 다른 사람들에게도 보내준다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;

				spawnGamePkt.mutable_player()->mutable_objectinfo()->set_objectid(player->objectInfo.objectid());
				spawnGamePkt.mutable_player()->set_gameobjecttype(Protocol::GameObjectType::GAME_OBJECT_TYPE_PLAYER);

				// 지금 접속중인 플레이어들에게 현재 접속한 플레이어의 스텟을 보낸다.
				auto stat = spawnGamePkt.mutable_player()->mutable_stat();
				stat->set_level(player->statInfo.level());

				stat->set_hp(player->statInfo.hp());
				stat->set_mp(player->statInfo.mp());

				stat->set_maxhp(player->statInfo.maxhp());
				stat->set_maxmp(player->statInfo.maxmp());

				stat->set_exp(player->statInfo.exp());
				stat->set_totalexp(player->statInfo.totalexp());

				stat->set_attack(player->statInfo.attack());

				// 스폰하는 캐릭터에 대한 정보를 보낸다.
				auto posInfo = spawnGamePkt.mutable_player()->mutable_objectinfo()->mutable_posinfo();
				posInfo->set_posx(player->objectInfo.mutable_posinfo()->posx());
				posInfo->set_posy(player->objectInfo.mutable_posinfo()->posy());
				posInfo->set_posz(player->objectInfo.mutable_posinfo()->posz());

				posInfo->set_yaw(player->objectInfo.mutable_posinfo()->yaw());
				posInfo->set_pitch(player->objectInfo.mutable_posinfo()->pitch());
				posInfo->set_roll(player->objectInfo.mutable_posinfo()->roll());

				posInfo->set_velox(player->objectInfo.mutable_posinfo()->velox());
				posInfo->set_veloy(player->objectInfo.mutable_posinfo()->veloy());
				posInfo->set_veloz(player->objectInfo.mutable_posinfo()->veloz());

				posInfo->set_speed(player->objectInfo.mutable_posinfo()->speed());
				posInfo->set_isinair(player->objectInfo.mutable_posinfo()->isinair());

				auto sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::SendFieldMonstersDataToPlayer(PlayerRef player)
	{
		// 현재 필드에 있는 몬스터 정보를 전달한다.
		for (auto monster : _monsters)
		{
			Protocol::S_MONSTERSPAWN monsterSpawnPacket;
			auto m = monster.second;

			monsterSpawnPacket.mutable_monster()->set_gameobjecttype(Protocol::GameObjectType::GAME_OBJECT_TYPE_MONSTER);

			auto objectInfo = monsterSpawnPacket.mutable_monster()->mutable_objectinfo();
			objectInfo->set_objectid(m->GetObjectID());

			auto posInfo = objectInfo->mutable_posinfo();
			posInfo->set_posx(m->GetPosInfo().posx());
			posInfo->set_posy(m->GetPosInfo().posy());
			posInfo->set_posz(m->GetPosInfo().posz());

			auto stat = monsterSpawnPacket.mutable_monster()->mutable_stat();
			stat->set_hp(monster.second->GetHP());

			auto sendBuffer = ClientPacketHandler::MakeSendBuffer(monsterSpawnPacket);
			player->ownerSession->Send(sendBuffer);
		}
	}

	void GameRoom::SendLeavePlayerDataToOther(PlayerRef player)
	{
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_DESPAWN despawnGamePkt;
				despawnGamePkt.set_playerid(player->objectInfo.objectid());

				auto sendBuffer = ClientPacketHandler::MakeSendBuffer(despawnGamePkt);
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}
	}

	void GameRoom::Update()
	{
		this_thread::sleep_for(30ms);
		if (_monsters.size() == 0) InitMonsterSet();
		CheckNearMonster();
	}

	void GameRoom::InitMonsterSet()
	{
		WRITE_LOCK;

		// 몬스터 초기화	
		// TODO : 데이터 테이블이나 json 등으로 묶기 
		MonsterRef monster = MakeShared<Monster>();
		monster->SetLocation(2140.f, 1300.f, 0.f);
		monster->SetHP(100);
		monster->SetObjectID(10001);
		monster->SetMovePoint(1.f);
		_monsters[monster->GetObjectID()] = monster;

		MonsterRef monster2 = MakeShared<Monster>();
		monster2->SetLocation(500, 1600, 0.f);
		monster2->SetHP(100);
		monster2->SetObjectID(10002);
		monster2->SetMovePoint(1.f);
		_monsters[monster2->GetObjectID()] = monster2;

		MonsterRef monster3 = MakeShared<Monster>();
		monster3->SetLocation(1050, 2750, 0.f);
		monster3->SetHP(100);
		monster3->SetObjectID(10003);
		monster3->SetMovePoint(1.f);
		_monsters[monster3->GetObjectID()] = monster3;

		MonsterRef monster4 = MakeShared<Monster>();
		monster4->SetLocation(550, 2340, 0.f);
		monster4->SetHP(100);
		monster4->SetObjectID(10004);
		monster4->SetMovePoint(1.f);
		_monsters[monster4->GetObjectID()] = monster4;
	}

	void GameRoom::CheckNearMonster()
	{
		WRITE_LOCK;

		if (_players.size() == 0) return;

		GConsoleLogger->WriteStdOut(FrokEngine::Color::BLUE, L"Monsters are checking near them\n");
		for (auto monster : _monsters)
		{
			// 몬스터가 죽었다면 굳이 체크할 필요가 없다.
			if (!monster.second->IsAlive())
				continue;

			for (auto player : _players)
			{
				// 플레이어가 HP가 0보다 작다면
				if (!(player.second->objectInfo.statinfo().hp() >= 0))
					continue;

				if(monster.second->IsPlayerInHitRange(player.second) && !monster.second->IsAttacking())
				{
					// 때리고 1초 쉰다.
					monster.second->HitPlayer(player.second);
					continue;
				}

				if (monster.second->IsPlayerInTraceRange(player.second) && !monster.second->IsAttacking())
				{
					// 추적한다.
					monster.second->MoveTo(player.second);
					Protocol::S_MOVE movePacket;

					movePacket.set_playerid(monster.second->GetObjectID());

					auto myPosInfo = movePacket.mutable_posinfo();
					myPosInfo->set_posx(monster.second->GetPosInfo().posx());
					myPosInfo->set_posy(monster.second->GetPosInfo().posy());
					myPosInfo->set_posz(monster.second->GetPosInfo().posz());

					myPosInfo->set_yaw(monster.second->GetPosInfo().yaw());
					myPosInfo->set_pitch(monster.second->GetPosInfo().pitch());
					myPosInfo->set_roll(monster.second->GetPosInfo().roll());

					myPosInfo->set_velox(monster.second->GetPosInfo().velox());
					myPosInfo->set_veloy(monster.second->GetPosInfo().veloy());
					myPosInfo->set_veloz(monster.second->GetPosInfo().veloz());

					auto sendBuffer = ClientPacketHandler::MakeSendBuffer(movePacket);
					Broadcast(sendBuffer);
				}
			}
		}
	}
}