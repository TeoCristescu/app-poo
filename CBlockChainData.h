#pragma once
#include "CMyException.h"
#include "CBlock.h"
#include<list>

class CBlockChainData
{
public:
	static CBlockChainData* getInstance();
	static void destroyInstance();

	int getSize();
	void store(CBlock block);

	list<CTran> getTrans(int index);

private:

	list<CBlock> mBlocks;

	static CBlockChainData* pInstance;
	CBlockChainData();
	~CBlockChainData();
};

