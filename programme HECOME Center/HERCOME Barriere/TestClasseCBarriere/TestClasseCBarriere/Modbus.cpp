#include "stdafx.h"
#include "Modbus.h"

//structure pour stocker et reperre facilement les donnée sur l'entete modbus
/*typedef struct 
{
	byte transactionId1 = 0x00;
	byte transactionId2 = 0x00;
	byte protocolId1 = 0x00;
	byte protocolId2 = 0x00;
	byte esclave = 0x01;
	byte codeFonction;
	byte longueur;

}headerModbus;
*/

// Constructeur, crée le socket et connect la liaison
CModbus::CModbus(CString adresseIp,CDialog* adress)
{
	adressDialog = adress;
	pMonSocket = new CMonSocket(this);
	pMonSocket->Create();
	connecter = pMonSocket->Connect(adresseIp, 502);
	pMonSocket->setAdress(adressDialog);
	//monSocket.setAdress(this);
}


CModbus::~CModbus()
{
	pMonSocket->Close();
	delete pMonSocket;
}


void CModbus::envoyerTrame(byte* message, int longueur)
{
	byte trame[256];
	int j = 7;
	//headerModbus monHeader;

	//Modbus 
	trame[0] = 0x02;//T_ID;//2 octet Transaction ID pas besoin
	trame[1] = 0x07;//T_ID;
	trame[2] = P_ID;//2 octet protocol id à mettre a 0
	trame[3] = P_ID;
	trame[4] = 0x00;
	trame[5] = longueur + 1;// 2 octet longueur du message à envoyer +1 car on prend en compte esclave
	trame[6] = ESCLAVE;// ici un esclave donc mettre 1


	// on met tout le message dans la trame
	for (int i = 0; i < longueur; i++)
	{
		trame[j] = message[i];
		j++;
	}

	// on envoye la trame avec sa longueur
	pMonSocket->Send(trame, j, 0);

}

bool CModbus::recevoirTrame()
{
	char trame[256];

	//recoit le trame
	pMonSocket->Receive(trame, 256);

	// on extrait les donnée de la trame;
	for (int i = 0; i <= trame[5] -2; i++)
		data[i] = trame[7 + i];

	// si une des entrées est ouvert on return true (ne marche que si on utilise une entrée)
	if (data[3] != 0x00)
		return true;

	return false;
}
