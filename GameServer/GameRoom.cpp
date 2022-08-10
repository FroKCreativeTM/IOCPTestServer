#include "pch.h"
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

		// TODO : DB에서 원래 플레이어가 있던 위치를 보내준다.
		// 즉 원래는 C_ENTER_GAME으로 접속하는 플레이어에 대한 id값만 보내는 식인 것

		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.mutable_player()->mutable_objectinfo()->set_objectid(static_cast<int32>(player->objectInfo.objectid()));

		// DB -> 내가 게임을 끌 때 
		// 그 최종값을 저장을 해두겠지?
		// 그럼 거기다가 스폰을 시킨다

		auto sendBuffer = ClientPacketHandler::MakeSendBuffer(enterGamePkt);
		player->ownerSession->Send(sendBuffer);

		// 지금 이미 입장한 사람들에 대한 정보를 지금 접속한 플레이어한테 보낸다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.mutable_player()->mutable_objectinfo()->set_objectid(otherPlayer.second->objectInfo.objectid());

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

				sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				player->ownerSession->Send(sendBuffer);
			}
		}

		// 내가 접속했다는 사실을 다른 사람들에게도 보내준다.
		for (auto otherPlayer : _players)
		{
			if (otherPlayer.first != player->objectInfo.objectid())
			{
				Protocol::S_SPAWN spawnGamePkt;
				spawnGamePkt.mutable_player()->mutable_objectinfo()->set_objectid(player->objectInfo.objectid());

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

				sendBuffer = ClientPacketHandler::MakeSendBuffer(spawnGamePkt);
				otherPlayer.second->ownerSession->Send(sendBuffer);
			}
		}

		// 현재 필드에 있는 몬스터 정보를 전달한다.
		for (auto monster : _monsters)
		{
			Protocol::S_MONSTERSPAWN monsterSpawnPacket;
			auto m = monster.second;
			
			auto objectInfo = monsterSpawnPacket.mutable_monster()->mutable_objectinfo();
			objectInfo->set_objectid(m->GetObjectID());

			auto posInfo = objectInfo->mutable_posinfo();
			posInfo->set_posx(m->GetPosInfo().posx());
			posInfo->set_posy(m->GetPosInfo().posy());
			posInfo->set_posz(m->GetPosInfo().posz());

			auto stat = monsterSpawnPacket.mutable_monster()->mutable_stat();
			stat->set_hp(monster.second->GetHP());

			sendBuffer = ClientPacketHandler::MakeSendBuffer(monsterSpawnPacket);
			player->ownerSession->Send(sendBuffer);
		}
	}

	void GameRoom::Leave(PlayerRef player)
	{
		// 요청한 NetworkID 값을 가진 사람이 없다면?
		// 이상상황!
		if (_players.find(player->objectInfo.objectid()) == _players.end()) return;

		// TODO : DB에 현재 유저가 있던 위치를 저장한다.

		_players.erase(player->objectInfo.objectid());

		cout << "Player Leaved ID : " << player->objectInfo.objectid() << endl;

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

	void GameRoom::InitMonsterSet()
	{
		// 몬스터 초기화	
		MonsterRef monster = MakeShared<Monster>();
		monster->SetLocation(2140.f, 1300.f, 0.f);
		monster->SetHP(100);
		monster->SetObjectID(10001);
		monster->SetMovePoint(10.f);
		_monsters[monster->GetObjectID()] = monster;

		MonsterRef monster2 = MakeShared<Monster>();
		monster2->SetLocation(500, 1600, 0.f);
		monster2->SetHP(100);
		monster2->SetObjectID(10002);
		monster2->SetMovePoint(10.f);
		_monsters[monster2->GetObjectID()] = monster2;

		MonsterRef monster3 = MakeShared<Monster>();
		monster3->SetLocation(1050, 2750, 0.f);
		monster3->SetHP(100);
		monster3->SetObjectID(10003);
		monster3->SetMovePoint(10.f);
		_monsters[monster3->GetObjectID()] = monster3;

		MonsterRef monster4 = MakeShared<Monster>();
		monster4->SetLocation(550, 2340, 0.f);
		monster4->SetHP(100);
		monster4->SetObjectID(10004);
		monster4->SetMovePoint(10.f);
		_monsters[monster4->GetObjectID()] = monster4;
	}

	void GameRoom::CheckNearMonster()
	{
		if (_monsters.size() == 0)
		{
			cout << "Monster Is Empty!!!!" << endl;
			InitMonsterSet();
		}

		for (auto monster : _monsters)
		{
			// 몬스터가 죽었다면 굳이 체크할 필요가 없다.
			if (!monster.second->IsAlive())
				continue;

			for (auto player : _players)
			{
				if(monster.second->IsPlayerInHitRange(player.second) && !monster.second->IsAttacking())
				{
					// 공격한다
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

				if (monster.second->IsPlayerInTraceRange(player.second) && !monster.second->IsAttacking())
				{
					// 추적한다.
					// monster.second->tra(player.second);
				}
			}
		}
	}
}