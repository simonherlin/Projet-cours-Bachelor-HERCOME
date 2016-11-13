
// TestClasseCCapteur.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CTestClasseCCapteurApp :
// Consultez TestClasseCCapteur.cpp pour l'implémentation de cette classe
//

class CTestClasseCCapteurApp : public CWinApp
{
public:
	CTestClasseCCapteurApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CTestClasseCCapteurApp theApp;