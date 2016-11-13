#include "stdafx.h"
#include "Bdd.h"
#pragma comment (lib, "libmysql.lib") 

CBdd::CBdd()
{
	
}


CBdd::~CBdd(void)
{
}

bool CBdd::Connect(char* login, char* password, char* bddname, char* IPAddress, int NumPort)
{
	int rep=0;
	MYSQL *pErreur;
	pMabase=mysql_init(NULL);
	rep=mysql_options(pMabase,MYSQL_READ_DEFAULT_GROUP,"option");
	pErreur=mysql_real_connect(pMabase,IPAddress,login,password,bddname,NumPort,NULL,0);
	if ((rep==0)&&(pErreur!=NULL))
		return true;
	else
		return false;

}

bool CBdd::WriteRequest(char* request)
{
	int result;

	result = mysql_query(pMabase, request);

	if (result == 0)
		return true;
	else
		return false;
}

vector<vector<CString>> CBdd::ReadRequest(char* request)
{
	//bool X = false;
	vector<vector<CString>> Vecteur;
	MYSQL_RES* presult;
	MYSQL_ROW ligne;
	CString Temp;
	int i = 0;
	vector<CString> Test;

	mysql_query(pMabase, request);
	//mysql_query(pMabase,"SELECT * FROM `bdd`.`vehicule` WHERE `VEH_Plaque`='MCLRNF1'");
	presult = mysql_use_result(pMabase);
	//presult = mysql_store_result(pMabase);


	while ((ligne = mysql_fetch_row(presult)) && (ligne != NULL))
	{

		i = 0;
		Temp = ' ';

		while (i<mysql_num_fields(presult))
		{
			Temp = ligne[i];
			Test.push_back(Temp);
			i++;
		};

		Vecteur.push_back(Test);
		Test.clear();
		//X = true;
	}
	//if (X)
	//return Vecteur;

	return Vecteur;
	
		

}

void CBdd::Close()
{
	mysql_close(pMabase);
}