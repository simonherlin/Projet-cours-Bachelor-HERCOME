
// HERCOME_Barriere.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CHERCOME_BarriereApp :
// Consultez HERCOME_Barriere.cpp pour l'implémentation de cette classe
//

class CHERCOME_BarriereApp : public CWinApp
{
public:
	CHERCOME_BarriereApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CHERCOME_BarriereApp theApp;