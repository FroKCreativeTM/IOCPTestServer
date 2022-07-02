#pragma once

namespace FrokEngine
{
	struct Pos
	{
		Pos(float x, float y, float z) :
			_x(x), _y(y), _z(z) {}

		float _x;
		float _y;
		float _z;

		bool operator==(const Pos& pos)
		{
			return _x == pos._x && _y == pos._y && _z == pos._z;
		}

		bool operator!=(const Pos& pos)
		{
			return !(*this == pos);
		}
	};

	// 맵 데이터를 그리드 방식으로 구현할까 고민중
	// 닌텐도에서 자주 써먹는 그 방식...?

	/*
	* 온라인 게임을 만들 때,
	* [클라는 어차피 모든 소스코드와 데이터가 공개되어 있다 가정하고,
	* 모든 보안은 서버에서 처리한다]~는 절대 법칙을 기억하시면 됩니다.
	* 따라서 당연히 클라에서 맵 정보는 조작할 수 있다고 가정하고
	* 이동할 수 없는 지역에 간다거나 하는 수상한 행동을 하면,
	* 이를 서버 측에서 검증하고 걸러줘야 합니다.
	* 이를 누락하면 스피드핵 등에 뚫릴 수 밖에 없는 것이죠.
	* 
	* -> 충돌은 클라가 먼저 판단하고 서버에서는 이를 러프하게 검사할 뿐!
	*/
	class MapData
	{
	public : 
		bool CanGo(Pos pos)
		{
			if (pos._x < _minX || pos._x > _maxX)
				return false;
			if (pos._y < _minY || pos._y > _maxY)
				return false;
			if (pos._z < _minZ || pos._z > _maxZ)
				return false;

			// 그 맵보다 낮게 있는 경우 false
			if (GetZ(pos._x, pos._y) > pos._z)
				return false;

			return true;
		}

		float GetZ(float x, float y)
		{
			return 0.f;
		}

	private : 
		// 맵에서 최대한으로 갈 수 있는 거리를 정해둔다.
		float _minX;
		float _minY;
		float _minZ;
		float _maxX;
		float _maxY;
		float _maxZ;
	};
}

