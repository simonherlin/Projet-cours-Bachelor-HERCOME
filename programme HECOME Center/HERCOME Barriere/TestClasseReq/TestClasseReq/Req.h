#pragma once

#include "Bdd.h"

#define ID "Herlin"
#define PASSWORD "17051989"
#define DATABASE "bdd"
#define ADRESSE "127.0.0.1"

class CReq
{
public:
	CReq();
	~CReq();
	bool connexion();
	bool preparerRequete(CString result);

private :
	CBdd maBdd;
	char requete[200];
};

