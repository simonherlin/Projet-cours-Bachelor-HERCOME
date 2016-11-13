#include "stdafx.h"
#include "Barrière.h"


CBarrière::CBarrière()
{
	
}


CBarrière::~CBarrière()
{
}

void CBarrière::ouvrir()
{
	//on ouvre la barriere
	//pMonCieh12->ecrireSortie(true);

	// on attend 2s
	Sleep(2000);

	// on fermer la barriere
	fermer();
}

void CBarrière::fermer()
{
	//pMonCieh12->ecrireSortie(false);
}
