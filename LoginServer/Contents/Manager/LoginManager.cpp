#include "pch.h"
#include "LoginManager.h"

namespace FrokEngine
{
	shared_ptr<LoginManager> LoginManager::_inst = nullptr;

	LoginManager::LoginManager()
	{
	}

	LoginManager::~LoginManager()
	{
		// DB에 대한 정리
	}

	bool LoginManager::Login(const string& id, const string& password)
	{
		// 임시용
		// TODO : DB에 연결해서 id를 조회한 뒤 만약 있다면 return true
		// 없다면 false
		string test = "testpassword";
		test = SHA256::GetInst()->toString(reinterpret_cast<const uint8_t*>(test.c_str()));
		cout << "test password : " << test << endl;
		return (id == "cscculture" && 
			password == test);
	}

	bool LoginManager::SignUp(const string& id, const string& password)
	{
		// 아직 가입은 막아둠
		// TODO : 패킷이 들어와서 일단 DB에 id를 조회하고 
		// 만약 있다면 이에 가입이 안 되니 return false를 하고
		// 만약 따로 없다면 SHA256을 통해서 패스워드를 암호화 한 뒤
		// 이에 대한 
		return false;
	}
}