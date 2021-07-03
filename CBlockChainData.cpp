#include "CBlockChainData.h"
#include "CBlockChainData.h"
#include "CMyException.h"

CBlockChainData* CBlockChainData::pInstance = nullptr;

CBlockChainData * CBlockChainData::getInstance()
{
	if (pInstance == nullptr)
		pInstance = new CBlockChainData;

	return pInstance;
}


void CBlockChainData::destroyInstance()
{
	if (pInstance != nullptr)
		delete pInstance;

	pInstance = nullptr;
}


int CBlockChainData::getSize()
{
	return mBlocks.size();
}


void CBlockChainData::store(CBlock block)
{
	mBlocks.push_back(block);
}


list<CTran> CBlockChainData::getTrans(int index)
{
	list<CBlock>::iterator it;

	for (it = mBlocks.begin(); it != mBlocks.end(); it++)
	{
		if (index == 0)
			return it->getTrans();

		index--;

	}
	throw new CMyException(ER_NOT_FOUND, "Eroare la cautare tr!");
}


CBlockChainData::CBlockChainData()
{
}


CBlockChainData::~CBlockChainData()
{
}
