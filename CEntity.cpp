#include "CEntity.h"

unsigned int CEntity::numberOfOrder = 1;

CEntity::CEntity()
{
	mAdress = numberOfOrder;
	numberOfOrder++;
}


CEntity::~CEntity()
{
}


unsigned int CEntity::genKey()
{
	return ((mAdress << 4) % 255) << 16;
}


unsigned int CEntity::getNrOfOrder()
{
	return numberOfOrder;
}
