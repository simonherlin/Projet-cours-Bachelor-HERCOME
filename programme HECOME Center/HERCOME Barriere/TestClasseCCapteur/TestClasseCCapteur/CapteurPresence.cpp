#include "stdafx.h"
#include "CapteurPresence.h"


CCapteurPresence::CCapteurPresence(CCIEH12* monCieh12)
{
	pMonCieh12 = monCieh12;
	pMonCieh12->setAdress(this);

	// pour exemple
	//presence = true;
}


CCapteurPresence::~CCapteurPresence()
{
}

void CCapteurPresence::demandePresence()
{

	pMonCieh12->lectureSortie();
	//presence = true;
	
}

void CCapteurPresence::recevoir()
{ 
	presence = pMonCieh12->retourDonne();
}

bool CCapteurPresence::getPresence()
{
	return presence;
}
