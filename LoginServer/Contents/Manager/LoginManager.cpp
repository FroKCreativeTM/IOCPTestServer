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
		// DB�� ���� ����
	}

	bool LoginManager::Login(const string& id, const string& password)
	{
		// �ӽÿ�
		// TODO : DB�� �����ؼ� id�� ��ȸ�� �� ���� �ִٸ� return true
		// ���ٸ� false
		string test = "testpassword";
		test = SHA256::GetInst()->toString(reinterpret_cast<const uint8_t*>(test.c_str()));
		cout << "test password : " << test << endl;
		return (id == "cscculture" && 
			password == test);
	}

	bool LoginManager::SignUp(const string& id, const string& password)
	{
		// ���� ������ ���Ƶ�
		// TODO : ��Ŷ�� ���ͼ� �ϴ� DB�� id�� ��ȸ�ϰ� 
		// ���� �ִٸ� �̿� ������ �� �Ǵ� return false�� �ϰ�
		// ���� ���� ���ٸ� SHA256�� ���ؼ� �н����带 ��ȣȭ �� ��
		// �̿� ���� 
		return false;
	}
}