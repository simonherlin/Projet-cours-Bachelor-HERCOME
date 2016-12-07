#include "CCapteurTemp.h"

CCapteurTemp::CCapteurTemp(int Pin)
{
	this->_Pin = Pin;
  pdht = new DHT(_Pin,DHT22);
}

CCapteurTemp::~CCapteurTemp()
{

}

void CCapteurTemp::Open()
{
	pdht->begin();
}

float CCapteurTemp::GetValeur()
{
  Serial.print("Température : ");
  Serial.println(pdht->readTemperature());
   Serial.print("Humidité : ");
  Serial.println(pdht->readHumidity());
  
  return pdht->computeHeatIndex(pdht->readTemperature(), pdht->readHumidity(), false);
}

void CCapteurTemp::Close()
{
  
}
