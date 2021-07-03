#include "CASICWorker.h"


CASICWorker::CASICWorker()
{
}


CASICWorker::CASICWorker(int consum) :_Worker(consum)
{
	mTip = ASIC;
}


CASICWorker::~CASICWorker()
{
}


bool CASICWorker::commitTran(CTran tr)
{
	ofstream out("out.txt", ios_base::app);



	if (validCheckSum(tr) == true)
	{
		out << "Tranzactie valida!" << endl;
		return true;
	}
	out << "Tranzactie invalida" << endl;

	return false;
}
