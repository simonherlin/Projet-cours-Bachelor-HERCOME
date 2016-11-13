#pragma once
#include "CIEH12.h"
class CCapteurPresence
{
public:
	CCapteurPresence(CCIEH12* modbus);
	~CCapteurPresence();
	void demandePresence();
	void recevoir();
	bool getPresence();

private :
	CCIEH12*	pMonCieh12;
	bool		presence;
};

