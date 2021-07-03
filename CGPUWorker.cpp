
#include "CGPUWorker.h"


CGPUWorker::CGPUWorker()
{
}


CGPUWorker::CGPUWorker(int consum) :_Worker(consum)
{
	mTip = GPU;
}


CGPUWorker::~CGPUWorker()
{
}


bool CGPUWorker::commitTran(CTran tr)
{
	if (validCheckSum(tr) == true)
	{
		cout << "Tranzactie valida!" << endl;
		return true;
	}
	cout << "Tranzactie invalida!" << endl;

	return false;
}
