#include "VirtualWire.h"
#include "CER433Arduino.h"
#include "CLumiere.h"
#define ADRESSE 3
#define TYPE 2

CLumiere* pLumiere
CER433Arduino* pMonER433;

boolean Veriftrame(char* tramerecue)
{
  char trame[9];
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


  if ( trame[1]=='E' && Ad == ADRESSE && Typ == TYPE)
  {
       
      return true;
  }
  else
  {
      return false;
  }
}


void setup() {
  // put your setup code here, to run once:
  pLumiere = new CLumiere(5);
 

}

void loop() {
  // put your main code here, to run repeatedly:

 if ( pMonER433->Receive(trame))
          {
             if (Veriftrame(trame))
             {
                  action = atoi(&trame[10]);
                  if (action == 1)
                    pLumiere->Eteindre();
                  else
                    pLumiere->Allumer();
             }
          }
}
