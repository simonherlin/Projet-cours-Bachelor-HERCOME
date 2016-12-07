#include "CCapteur.h"
#include "DHT.h"

class CCapteurTemp : public CCapteur
{
public:
	CCapteurTemp(int Pin);
	~CCapteurTemp();
	void Open();
	void Close();
	float GetValeur();
private:
	int _Pin;
  DHT* pdht;

};
