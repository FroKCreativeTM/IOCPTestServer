#pragma once

namespace FrokEngine
{
	// 
	class ObjectManager
	{
	public : 
		ObjectManager() {}
		static shared_ptr<ObjectManager> GetInst()
		{
			if (_inst == nullptr)
				_inst = make_shared<ObjectManager>();
			return _inst;
		}

		template <typename T>
		inline T Add()
		{
			T gameObject = new T();
		
			WRITE_LOCK;
			{
				gameObject.id = 
			}
		}
		
		int GenerateId(Protocol::GameObjectType type)
		{
			WRITE_LOCK;
			return ((int)type << 24) | (_counter++)
		}

	private : 
		USE_LOCK;

		static shared_ptr<ObjectManager> _inst;

		// [UNUSED(1)][TYPE(7)][ID(24)]
		int _counter = 0;
		map<int, PlayerRef> _players;
	};
}

