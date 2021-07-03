#pragma once
#include "CTran.h"

class IWorker
{
public:
	IWorker();
	virtual ~IWorker();

	virtual bool commitTran(CTran tr) = 0;
	virtual int getConsum() = 0;
};

