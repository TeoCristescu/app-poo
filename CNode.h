#pragma once
#include<list>
using namespace std;
#include "CGPUWorker.h"
#include "CASICWorker.h"
#include "CEntity.h"

class CNode : public CEntity
{
public:
	CNode();
	~CNode();

	void addWorker(t_tip tip, int consum);


	void addTran(CTran tr);

	int getListSize();

	void emptyTran();

	void commitTrans();

	bool operator==(CNode nod);

	int getWorkSize();

private:
	list<IWorker*> mWorkers;
	long mStartTime;

	list<CTran> mTrans;

};

