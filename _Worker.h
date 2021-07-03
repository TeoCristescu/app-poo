#pragma once
#include "IWorker.h"
#include <iostream>
#include <fstream>
using namespace std;

enum t_tip { GPU, ASIC };

class _Worker :public IWorker
{
public:
	_Worker();
	_Worker(int consum);
	virtual ~_Worker();

	int getConsum();
	

protected:
	bool validCheckSum(CTran tr);

	int mConsum;
	t_tip mTip;
};

