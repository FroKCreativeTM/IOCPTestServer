#pragma once

namespace FrokEngine
{
	class Player;

	class LoginManager
	{
	public:
		LoginManager();
		~LoginManager();

		static shared_ptr<LoginManager> GetInst()
		{
			if (!_inst) 
			{
				_inst = make_shared<LoginManager>();
			}
			return _inst;
		}

	public:
		bool Login(const string& id, const string& password);
		bool SignUp(const string& id, const string& password);

	private:
		// ���� �ʿ��� �� ������
		// USE_LOCK;
		static vector<PlayerRef>		_loginedPlayers;
		static shared_ptr<LoginManager> _inst;
	};
}

