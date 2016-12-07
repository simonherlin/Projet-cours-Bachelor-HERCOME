#include "CRelais.h"

class CStore
{
public :
	CStore();
	~CStore();
	void Monter();
	void Descendre();
	void Stop();
private:
	CRelais * pRelaisBas;
	CRelais * pRelaisHaut;
};