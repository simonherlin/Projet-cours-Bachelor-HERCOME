#include "stdafx.h"
#include "Req.h"


CReq::CReq()
{
}


CReq::~CReq()
{
}

bool CReq::connexion()
{
	return maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);
}

bool CReq::preparerRequete(CString result)
{
	vector<vector<CString>> resultatPlaque;
	sprintf_s(requete, "SELECT * FROM `bdd`.`vehicule` WHERE `VEH_Plaque`='%S'", result);
	resultatPlaque =  maBdd.ReadRequest(requete);

	if (resultatPlaque.size() > 0)
		return true;
	else
		return false;
}