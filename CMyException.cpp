#include "CMyException.h"
#include <string.h>

CMyException::CMyException()
{
	mCode = STATUS_OK;
	pMessage = nullptr;
}


CMyException::CMyException(int code, const char * message)
{
	mCode = code;
	pMessage = _strdup(message);
	
}


CMyException::~CMyException()
{
	if (pMessage != nullptr)
		delete[] pMessage;

	pMessage = nullptr;
}


void CMyException::message()
{
	cout << "EXCEPTIE:" << mCode << pMessage << endl;
}


int CMyException::getCode()
{
	return mCode;
}
