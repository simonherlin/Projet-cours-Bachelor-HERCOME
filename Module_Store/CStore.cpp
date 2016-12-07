#include "CStore.h"

CStore::CStore()
{
	pRelaisBas = new CRelais(4);
	pRelaisHaut = new CRelais(5);
}

CStore::~CStore()
{

}

void CStore::Stop()
{
	pRelaisBas->EcrireSortie(false);
	pRelaisHaut->EcrireSortie(false);
}

void CStore::Monter()
{
	pRelaisHaut->EcrireSortie(true);
}

void CStore::Descendre()
{
	pRelaisBas->EcrireSortie(true);
}
