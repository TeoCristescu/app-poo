#pragma once
#include "CEntity.h"

class ATMBlockChainSystem;

class CClient : public CEntity
{
public:
	CClient();
	~CClient();

	void sendTran(ATMBlockChainSystem* sys, int sum, int cost, int toId);

private:
	int computeCheckSum(int sum, int myId, int toId, int cost, long timeStamp);
};

