#include "CRelais.h"
#include <Arduino.h>

CRelais::CRelais(int Pin)
{
	_Pin = Pin;
	pinMode(_Pin, OUTPUT);
}

CRelais::~CRelais()
{

}

void CRelais::EcrireSortie(bool Ordre)
{
	if (Ordre == true)
		digitalWrite(_Pin, HIGH);
	else
		digitalWrite(_Pin, LOW);
}
