
// TestClasseBddDlg.h : fichier d'en-tête
//

#pragma once

#include "Bdd.h"

#define ID "Herlin"
#define PASSWORD "17051989"
#define DATABASE "bdd"
#define ADRESSE "127.0.0.1"

// boîte de dialogue CTestClasseBddDlg
class CTestClasseBddDlg : public CDialogEx
{
// Construction
public:
	CTestClasseBddDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTCLASSEBDD_DIALOG };
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
public:
	CString m_sConnexion;
//	CString m_sUpdate;
	CString m_sLire;
	CString m_sUpdate;
	afx_msg void OnBnClickedConnec1();

private:
	CBdd maBdd;
	bool connect;
public:
	afx_msg void OnBnClickedConnec2();
	afx_msg void OnBnClickedUpd1();
	afx_msg void OnBnClickedUpd2();
	afx_msg void OnBnClickedLire1();
	afx_msg void OnBnClickedLire2();
};
