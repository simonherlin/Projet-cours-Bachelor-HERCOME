
// TestClasseCBarriereDlg.h : fichier d'en-tête
//

#pragma once
#include "Barrière.h"
#include "CIEH12.h"

// boîte de dialogue CTestClasseCBarriereDlg
class CTestClasseCBarriereDlg : public CDialogEx
{
// Construction
public:
	CTestClasseCBarriereDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCLASSECBARRIERE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private :
	CCIEH12* pMonCIEH12;
	CBarrière* pMaBarriere;
public:
	afx_msg void OnBnClickedOuvrir();
	afx_msg void OnBnClickedFermer();
	void receive();
};
