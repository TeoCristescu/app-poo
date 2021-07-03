
#include "ATMBlockChainSystem.h"
#include "CClient.h"
#include "CMyException.h"
#include <time.h>
#include "conio.h"

void main()
{
	try {
		srand(time(NULL));

		list<CNode> nodes;

		CNode nod1, nod2;
		nod1.addWorker(GPU, 4);
		nod1.addWorker(ASIC, 2);

		nod2.addWorker(ASIC, 2);
		nod2.addWorker(GPU, 4);

		nodes.push_back(nod1);
		nodes.push_back(nod2);


		ATMBlockChainSystem* sys = new ATMBlockChainSystem(2, nodes);

		CClient cl;
		CClient cl2;
		cl.sendTran(sys, 100, 50, 2);

		cl2.sendTran(sys, 20, 30, 3);

		sys->getBalance(3);

		sys->processPower();

		if (nod1 == nod2)
			cout << "da";
		else
			cout << "nu";

	}
	catch (CMyException* e)
	{
		e->message();
		delete e;
	}


	_getch();
}

