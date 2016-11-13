#include "stdafx.h"
#include "CIEH12.h"


CCIEH12::CCIEH12(CDialog* adress)
{
	monAdresseIp = "192.168.10.50";
	pMonModbus = new CModbus(monAdresseIp,adress);
}


CCIEH12::~CCIEH12()
{
	delete pMonModbus;
}

void CCIEH12::ecrireSortie(bool choix)
{
	// partie data de la trame modbus tcp
	//pour test choix = true;
	byte data[10];
	data[0] = FC_ECIRE;
	data[1] = 0x00;
	data[2] = 0x08;
	data[3] = 0x00;
	data[4] = WORLD_COUNT;
	data[5] = BYTE_COUNT;
	data[6] = 0x00;
	if (choix == ECRIREUN)
		data[7] = 0x01;
	else
		data[7] = 0x00;
	//envoie de la trame, true pour ecriture
	pMonModbus->envoyerTrame(data, 8);

}


void CCIEH12::lectureSortie()
{
	byte data[10];
	// partie data de la trame modbus tcp
	data[0] = FC_LIRE;
	data[1] = 0x00;
	data[2] = 0x00;
	data[3] = 0x00;// premier octet du world count
	data[4] = WORLD_COUNT;// deuxiemem octet du world count

	// envoie de la trame, false pour lecture
	pMonModbus->envoyerTrame(data, 5);


}

bool CCIEH12::retourDonne()
{
	return pMonModbus->recevoirTrame();
}
/*
void CCIEH12::setAdress(CCapteurPresence* adress)
{
	pMonCapteur = adress;
}
*/