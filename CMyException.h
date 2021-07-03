#pragma once
#include<iostream>
#include<string.h>
#include "exceptii.h"

using namespace std;

class CMyException
{
public:
	CMyException();
	CMyException(int code, const char* message);
	~CMyException();

	void message();
	int getCode();

private:
	int mCode;
	char* pMessage;
};

