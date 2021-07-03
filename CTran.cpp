#include "CTran.h"

int CTran::nrOfOrder = 0;

CTran::CTran()
{
}


CTran::~CTran()
{
}


CTran::CTran(int sum, int cost, int fromId, int toId, int checkSum, long timeStamp, int key)
{
	mTrSum = sum;
	mTrCost = cost;
	mClId = fromId;
	mRecId = toId;
	mCheckSum = checkSum;
	mTimeStamp = timeStamp;
	mClKey = key;

	mId = nrOfOrder++;
}


int CTran::getId()
{
	return mId;
}


int CTran::getClId()
{
	return mClId;
}



int CTran::getCost()
{
	return mTrCost;
}


int CTran::getRecId()
{
	return mRecId;
}


int CTran::getSum()
{
	return mTrSum;
}


