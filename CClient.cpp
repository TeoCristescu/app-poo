#include "CClient.h"
#include <time.h>
#include "CTran.h"
#include "ATMBlockChainSystem.h"

CClient::CClient()
{
	mTip = CLIENT;
}


CClient::~CClient()
{
}


void CClient::sendTran(ATMBlockChainSystem * sys, int sum, int cost, int toId)
{
	long timeStamp = time(0);

	CTran tr(sum, cost, this->mAdress, toId, computeCheckSum(sum, this->mAdress, toId, cost, timeStamp), timeStamp, this->genKey());

	sys->processTran(tr);
}


int CClient::computeCheckSum(int sum, int myId, int toId, int cost, long timeStamp)
{
	return (sum + myId + toId + cost + timeStamp) % this->genKey();
}
