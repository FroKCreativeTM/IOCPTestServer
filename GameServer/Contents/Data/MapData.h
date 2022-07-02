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

	// �� �����͸� �׸��� ������� �����ұ� �����
	// ���ٵ����� ���� ��Դ� �� ���...?

	/*
	* �¶��� ������ ���� ��,
	* [Ŭ��� ������ ��� �ҽ��ڵ�� �����Ͱ� �����Ǿ� �ִ� �����ϰ�,
	* ��� ������ �������� ó���Ѵ�]~�� ���� ��Ģ�� ����Ͻø� �˴ϴ�.
	* ���� �翬�� Ŭ�󿡼� �� ������ ������ �� �ִٰ� �����ϰ�
	* �̵��� �� ���� ������ ���ٰų� �ϴ� ������ �ൿ�� �ϸ�,
	* �̸� ���� ������ �����ϰ� �ɷ���� �մϴ�.
	* �̸� �����ϸ� ���ǵ��� � �ո� �� �ۿ� ���� ������.
	* 
	* -> �浹�� Ŭ�� ���� �Ǵ��ϰ� ���������� �̸� �����ϰ� �˻��� ��!
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

			// �� �ʺ��� ���� �ִ� ��� false
			if (GetZ(pos._x, pos._y) > pos._z)
				return false;

			return true;
		}

		float GetZ(float x, float y)
		{
			return 0.f;
		}

	private : 
		// �ʿ��� �ִ������� �� �� �ִ� �Ÿ��� ���صд�.
		float _minX;
		float _minY;
		float _minZ;
		float _maxX;
		float _maxY;
		float _maxZ;
	};
}

