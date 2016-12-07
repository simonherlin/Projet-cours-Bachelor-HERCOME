#include "VirtualWire.h"
#include "CER433Arduino.h"
#include "CStore.h"
#define ADRESSE 1
#define TYPE 1

CER433Arduino * pMonER433;
CStore * pStore;


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





void ExecuterOrdre(int ordre)
{
  int action = ordre;
  char trame[9];
  unsigned long timer = millis();
  do
  {
     switch(action)
     {
      case 1:
           action = 0;
          pStore->Stop();
      break;
      case 2 :
           action = 0;
          pStore->Monter();
         do
          {
  
          if ( pMonER433->Receive(trame))
          {
             if (Veriftrame(trame))
             {
                  action = atoi(&trame[7]);
             }
          }
        }while((action == 0) && (30000 > millis() - timer));
      break;
      case 3:
        action = 0;
        
         pStore->Descendre();
         do
          {
  
          if ( pMonER433->Receive(trame))
          {
             if (Veriftrame(trame))
             {
                  action = atoi(&trame[7]);
             }
          }
        }while((action == 0) && (30000 > millis() - timer));
      break;
       
     }     
    Serial.println("STOP");
    pStore->Stop();
  }while(action != 0);
}




void setup()
{
  Serial.begin(9600);
  pMonER433 = new CER433Arduino(-1,2);
  pStore = new CStore();
  pStore->Stop();
}





void loop()
{
  char trame[9];
  int action = 0;
  strcpy (trame,"");
    pMonER433->Receive(trame);
       
      if (Veriftrame(trame))
      {
          action= atoi(&trame[7]);
          ExecuterOrdre(action);
      }
}
