#include "CCapteurTemp.h"
#include "CER433Arduino.h"
#include "LowPower.h"
#include "CRelais.h"
#define ADRESSE 2
#define TYPE 4

CCapteurTemp* pCapteurTemp;
CER433Arduino* pMonER433;
CRelais* pRelaisThermo;

boolean Veriftrame(char* tramerecue)
{
  char trame[12];
  char Adresse[4];
  char Type[3];
  int Ad = 0;
  int Typ = 0;
  int j=0;

  strcpy(Adresse, "");
  strcpy(Type, "");
  strcpy(trame,"");
  strcpy(trame,tramerecue);
  
  for (int i=2; i<5 ; i++)
  {
    Adresse[j]=trame[i];
    if (i<4)
      Type[j]= trame[i+3];
    j++;
  }


  Adresse[3] = '\0';
  Type[2] = '\0';
  
  Ad=atoi(Adresse);
  Typ=atoi(Type);


  if ( trame[1]=='E' && ( Ad == ADRESSE || Ad == 999) &&  Typ == TYPE)
  {
       
      return true;
  }
  else
  {
      return false;
  }
}

void setup()
{
  Serial.begin(9600);
  pRelaisThermo = new CRelais(4);
  pRelaisThermo->EcrireSortie(true);
}

void loop()
{
  int action = 0;

  float tempactuelf = 0;
  float tempdesf = 0;

  char trame[12];
  char trameenvoye[12];
  char type[3];
  char adresse[4];
  char tempact[4]; //taille max de 20 caractère pour le message, pour l'exemple
  char tempdes[5];
 
  pCapteurTemp= new CCapteurTemp(2);
  pCapteurTemp->Open();
  tempactuelf = pCapteurTemp->GetValeur();

  
   dtostrf(tempactuelf, 1,1,tempact );
   dtostrf(TYPE, 2,0, type);
   dtostrf( ADRESSE, 3,0, adresse);

  trameenvoye[0] = 0x02;
  trameenvoye[1] = 'R';
  trameenvoye[2] = adresse[0];
  trameenvoye[3] = adresse[1];
  trameenvoye[4] = adresse[2];
  trameenvoye[5] = type[0];
  trameenvoye[6] = type[1];
  trameenvoye[7] = tempact[0];
  trameenvoye[8] = tempact[1];
  trameenvoye[9] = tempact[2];
  trameenvoye[10] = tempact[3];
  trameenvoye[11] = 0x03;
  
//    trameenvoye = {0x02,'R',adresse[0],adresse[1],adresse[2],type[0],type[1],tempact[0],tempact[1],tempact[2],tempact[3],0x03};
  
    pMonER433 = new CER433Arduino(3,12);
    pMonER433->Send(trameenvoye);

    unsigned long timer = millis();
    
    do
    {
      
        if ( pMonER433->Receive(trame))
        {
          if (Veriftrame(trame))
          {
                  pRelaisThermo = new CRelais(4);
                  pRelaisThermo->EcrireSortie(false);
                  action = 1;
                 for (int i = 0; i< 4; i++)
                 {
                    tempdes[i]=trame[i+7];
                 }
                 tempdes[4]= '\0';
                 tempdesf = atof (tempdes);
                 Serial.println(tempdesf);
                 Serial.println(tempactuelf);

                 if (tempdesf > tempactuelf)
                      pRelaisThermo->EcrireSortie(false);
                 else
                      pRelaisThermo->EcrireSortie(true);
          }
        }
    }while((action == 0) && (15000 > millis() - timer));


    //Sommeil profond pendant 8S * 38 = (environ) 5Min
   for (int i = 0; i < 1; i++) { 
    LowPower.powerDown(SLEEP_8S, ADC_ON, BOD_ON); 
  }
}

