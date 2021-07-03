#pragma once
#include "CTran.h"
#include <list>
using namespace std;

class CBlock
{
public:
	CBlock();
	CBlock(list<CTran> trs, int checkSum, long timeStamp);
	~CBlock();

	list<CTran> getTrans();

private:
	list<CTran> mTrans;
	int mCheckSum;
	long mTimeStamp;
};

