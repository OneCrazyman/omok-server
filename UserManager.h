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
	virtual ~UserManager(); // 부모 클래스의 포인터로 자식 클래스의 객체를 삭제할 때 소멸자가 호출 되지 않는 문제 방지

	void Init(const int maxUserCount);

	ERROR_CODE AddUser(const int sessionIndex, const char* pszID);
	ERROR_CODE RemoveUser(const int sessionIndex);

	std::tuple<ERROR_CODE, User*> GetUser(const int sessionIndex);

private:
	//...
};