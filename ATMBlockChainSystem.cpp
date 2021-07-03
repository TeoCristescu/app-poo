
#include "ATMBlockChainSystem.h"
#include "CBlockChainData.h"
#include "CEntity.h"

ATMBlockChainSystem::ATMBlockChainSystem()
{
}

ATMBlockChainSystem::ATMBlockChainSystem(int max_tr, list<CNode>& node)
{
	mNrMax = max_tr;
	mNodes = node;



	list<CTran> trs;

	for (int i = 0; i <= CEntity::getNrOfOrder(); i++)
		trs.push_back(*new CTran(100, 0, 0, i, 0, 0, 0));

	CBlockChainData* data = CBlockChainData::getInstance();

	CBlock* genesis = new CBlock(trs, 0, 0);

	data->store((*genesis));

}


ATMBlockChainSystem::~ATMBlockChainSystem()
{
}


void ATMBlockChainSystem::getBalance(int adress)
{
	int bal = 0;

	CBlockChainData* data = CBlockChainData::getInstance();

	list<CTran> trs;
	list<CTran>::iterator it;
	int sum = 0;
	bool found = false;

	for (int i = 0; i < data->getSize(); i++)
	{
		trs = data->getTrans(i);

		for (it = trs.begin(); it != trs.end(); it++)
			if (it->getClId() == adress) 
			{
				sum -= it->getCost();
				found = true;
			}
			else if (it->getRecId() == adress)
			{
				sum += it->getSum();
				found = true;
			}

	}

	if (found == false)
		throw new CMyException(ER_NOT_FOUND, "Adresa este gresita!");

	cout << "Pentru:" << adress << "are in cont:" << sum << endl;
}


void ATMBlockChainSystem::processTran(CTran tr)
{
	list<CNode>::iterator it;

	for (it = mNodes.begin(); it != mNodes.end(); it++) //adaug tranzactia la fiecare nod
		it->addTran(tr);

	it = mNodes.begin();

	if (it->getListSize() == mNrMax)
		this->commitTrans();
}

void ATMBlockChainSystem::processPower()
{
	int n = 0;
	list<CNode>::iterator it;

	for (it = mNodes.begin(); it != mNodes.end(); it++)
		n = n + it->getWorkSize();

	cout << "Retea dispunde de " << n << " workeri de procesare!" << endl;
}


void ATMBlockChainSystem::commitTrans()
{
	int nod = rand() % mNodes.size();

	list<CNode>::iterator it;

	it = mNodes.begin();

	for (int i = 0; i < nod; i++)
		it++;;

	it->commitTrans(); //nodul va comite tranzactiile

	for (it = mNodes.begin(); it != mNodes.end(); it++)
		it->emptyTran();


}
