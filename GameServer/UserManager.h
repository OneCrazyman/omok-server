#pragma once
#include "ErrorCode.h"

class User;

class UserManager {
public:
	UserManager();
	virtual ~UserManager();

	void Init(const int maxUserCount);

	
};