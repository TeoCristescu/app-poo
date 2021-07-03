#pragma once
#include "_Worker.h"
class CGPUWorker :public _Worker
{
public:
	CGPUWorker();
	CGPUWorker(int consum);
	~CGPUWorker();

	bool commitTran(CTran tr);
};

