#pragma once

enum ent_tip { NODE, CLIENT };
class CEntity
{
public:
	CEntity();
	~CEntity();

	unsigned int genKey();

	static unsigned int getNrOfOrder();

protected:
	static unsigned int numberOfOrder;

	unsigned int mAdress;
	ent_tip mTip;
};

