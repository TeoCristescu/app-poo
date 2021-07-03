#include "CNode.h"
#include <time.h>
#include "CBlockChainData.h"

CNode::CNode()
{
	mTip = NODE;
	mStartTime = 0;
}


CNode::~CNode()
{
}


void CNode::addWorker(t_tip tip, int consum)
{
	if (tip == ASIC)
		mWorkers.push_back(new CASICWorker(consum));
	else if (tip == GPU)
		mWorkers.push_back(new CGPUWorker(consum));
}


void CNode::addTran(CTran tr)
{
	mTrans.push_back(tr);
}


int CNode::getListSize()
{
	return mTrans.size();
}


void CNode::emptyTran()
{
	mTrans.empty();
}


void CNode::commitTrans()
{

	list<CTran>::iterator it;
	list<IWorker*>::iterator wk;
	wk = mWorkers.begin();
	list<CTran> block;

	for (it = mTrans.begin(); it != mTrans.end(); it++)
	{

		if ((*wk)->commitTran((*it)) == true)
			block.push_back((*it));
		wk++;

		if (wk == mWorkers.end())
			wk = mWorkers.begin();
	}

	CBlockChainData* data = CBlockChainData::getInstance(); 

	int sum = 0;

	for (it = block.begin(); it != block.end(); it++)
		sum = sum + it->getId();


	sum = sum % (data->getSize() + 1); 

	sum = sum + this->mAdress; 

	data->store(*new CBlock(block, sum, time(0)));
}

bool CNode::operator==(CNode nod)
{
	int p1 = 0, p2 = 0;
	list<IWorker*>::iterator it;

	long ct = (time(0) - mStartTime) / 1000; 

	for (it = mWorkers.begin(); it != mWorkers.end(); it++)
		p1 = p1 + ct * (*it)->getConsum();

	for (it = nod.mWorkers.begin(); it != nod.mWorkers.end(); it++)
		p2 = p2 + ct * (*it)->getConsum();

	if (p1 == p2)
		return true;

	return false;
}


int CNode::getWorkSize()
{
	return mWorkers.size();
}



