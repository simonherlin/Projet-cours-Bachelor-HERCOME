#include "stdafx.h"
#include "Barrière.h"


CBarrière::CBarrière(CCIEH12 *monCieh12)
{
	pMonCieh12 = monCieh12;
}


CBarrière::~CBarrière()
{
}

void CBarrière::ouvrir()
{
	//on ouvre la barriere
	pMonCieh12->ecrireSortie(true);

	// on attend 2s
	Sleep(2000);

	// on fermer la barriere
	fermer();
}

void CBarrière::fermer()
{
	pMonCieh12->ecrireSortie(false);
}
