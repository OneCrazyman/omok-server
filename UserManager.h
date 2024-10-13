#pragma once
#include <unordered_map>
#include <deque>
#include <string>
#include <vector>

#include "ErrorCode.h"

class User;

class UserManager
{
public:
	UserManager();
	virtual ~UserManager(); // �θ� Ŭ������ �����ͷ� �ڽ� Ŭ������ ��ü�� ������ �� �Ҹ��ڰ� ȣ�� ���� �ʴ� ���� ����

	void Init(const int maxUserCount);

	ERROR_CODE AddUser(const int sessionIndex, const char* pszID);
	ERROR_CODE RemoveUser(const int sessionIndex);

	std::tuple<ERROR_CODE, User*> GetUser(const int sessionIndex);

private:
	//...
};