#include "StdAfx.h"
#include "MonSocket.h"
#include "TestClasseCBarriereDlg.h"
//#include "Modbus.h" // bien changer l'adresse si on change de projet


CMonSocket::CMonSocket(CModbus* adress)
{
	//num=0;
	//etatConnect=false;
	pModbus = adress;
}


CMonSocket::~CMonSocket(void)
{
}


void CMonSocket::OnReceive( int nErrorCode )// evenement reception message
{
	// pointeur vers notre principale pour appeller la méthode receive et ainsi bien recevoir le message
//	pModbus->recevoirTrame();
	((CTestClasseCBarriereDlg*)fenetre)->receive();


}

void CMonSocket::setAdress( CDialog* adresse)// recuper l'adresse
{
	fenetre = adresse;
}


void CMonSocket::OnAccept(int nErrorCode )// evenement acceptation de la communication
{
	//((CProjetGraphique5MarsDlg*)fenetre)->accepter();
}

void CMonSocket::OnConnect(int nErrorConnect)// evenement de la connection
{
	//((CProjetGraphique5MarsDlg*)fenetre)->connecter();
	//etatConnect=true;
}

void CMonSocket::OnClose(int nErrorConnect)// evenement de la fermetur de la connection
{
	//((CProjetGraphique5MarsDlg*)fenetre)->close();
	//etatConnect=false;
}

void CMonSocket::SetNum(int numero)
{
	num=numero;
}

bool CMonSocket::GetConnect()
{
	return etatConnect;
}