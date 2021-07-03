
#include "_Worker.h"


_Worker::_Worker()
{
}


_Worker::_Worker(int consum)
{
	mConsum = consum;
}


_Worker::~_Worker()
{
}


int _Worker::getConsum()
{
	return mConsum;
}


bool _Worker::validCheckSum(CTran tr)
{
	if (tr.mCheckSum ==
		(tr.mTrSum + tr.mClId + tr.mRecId + tr.mTrCost + tr.mTimeStamp) % tr.mClKey)
		return true;

	return false;
}
