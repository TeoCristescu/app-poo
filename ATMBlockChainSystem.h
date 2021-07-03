#pragma once
#include "CNode.h"

class ATMBlockChainSystem
{
public:
	ATMBlockChainSystem();
	ATMBlockChainSystem(int max_tr, list<CNode>& node);
	~ATMBlockChainSystem();

	void getBalance(int adress);

	void processTran(CTran tr);

	void processPower();

private:
	void commitTrans();

	int mNrMax; 
	list<CNode> mNodes;
};

