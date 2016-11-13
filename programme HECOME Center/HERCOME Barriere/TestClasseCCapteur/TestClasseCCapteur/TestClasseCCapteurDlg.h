
// TestClasseCCapteurDlg.h : fichier d'en-tête
//

#pragma once
#include "CIEH12.h"
#include "CapteurPresence.h"


// boîte de dialogue CTestClasseCCapteurDlg
class CTestClasseCCapteurDlg : public CDialogEx
{
// Construction
public:
	CTestClasseCCapteurDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCLASSECCAPTEUR_DIALOG };
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
	CCapteurPresence* pMonCapteur;
public:
	afx_msg void OnBnClickedObtetat();
	void receive();
	CString m_sReponse;
};
