#pragma once
#include "_Worker.h"
class CASICWorker :
	public _Worker
{
public:
	CASICWorker();
	CASICWorker(int consum);
	~CASICWorker();

	bool commitTran(CTran tr);

};

