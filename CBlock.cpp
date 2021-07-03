#include "CBlock.h"


CBlock::CBlock()
{
}


CBlock::CBlock(list<CTran> trs, int checkSum, long timeStamp)
{
	mTrans = trs;
	mCheckSum = checkSum;
	mTimeStamp = timeStamp;
}


CBlock::~CBlock()
{
}


list<CTran> CBlock::getTrans()
{
	return mTrans;
}
