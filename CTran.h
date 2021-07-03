#pragma once
class CTran
{
public:
	CTran();
	~CTran();

	CTran(int sum, int cost, int fromId, int toId, int checkSum, long timeStamp, int key);

	friend class _Worker;

	int getId();
	int getClId();
	int getCost();
	int getRecId();
	int getSum();

private:
	static int nrOfOrder;

	int mTrSum; //suma transferata
	int mTrCost; //costul tranzactiei
	int mClId; //id-ul clientrului care trimite
	int mRecId; //id-ul clientului care o primieste
	int mCheckSum;
	long mTimeStamp;
	int mClKey;
	int mId;

};

