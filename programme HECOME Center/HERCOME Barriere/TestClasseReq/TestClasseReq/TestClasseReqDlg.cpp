
// TestClasseReqDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TestClasseReq.h"
#include "TestClasseReqDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue CTestClasseReqDlg



CTestClasseReqDlg::CTestClasseReqDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTCLASSEREQ_DIALOG, pParent)
	, m_sResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestClasseReqDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULT, m_sResult);
}

BEGIN_MESSAGE_MAP(CTestClasseReqDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CTestClasseReqDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_DISPO1, &CTestClasseReqDlg::OnBnClickedDispo1)
	ON_BN_CLICKED(IDC_DISPO2, &CTestClasseReqDlg::OnBnClickedDispo2)
END_MESSAGE_MAP()


// gestionnaires de messages pour CTestClasseReqDlg

BOOL CTestClasseReqDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	connexion = false;

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CTestClasseReqDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CTestClasseReqDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CTestClasseReqDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestClasseReqDlg::OnBnClickedConnect()
{
	connexion = maRequete.connexion();
	if (connexion)
		m_sResult.Format(L"connexion réussi");
	else
		m_sResult.Format(L"connexion échouer");

	UpdateData(FALSE);
}


void CTestClasseReqDlg::OnBnClickedDispo1()
{
	if (connexion)
	{
		bool X;
		X = maRequete.preparerRequete(L"DM195YZ");
		if (X)
			m_sResult.Format(L"plaque trouver");
		else
			m_sResult.Format(L"plaque non trouver");
	}
	else
	{
		m_sResult.Format(L"Non connecter a la base de donnée");
	}


	UpdateData(FALSE);
}


void CTestClasseReqDlg::OnBnClickedDispo2()
{
	if (connexion)
	{
		bool X;
		X = maRequete.preparerRequete(L"OURSBRUN");
		if (X)
			m_sResult.Format(L"plaque trouver");
		else
			m_sResult.Format(L"plaque non trouver");
	}
	else
	{
		m_sResult.Format(L"Non connecter a la base de donnée");
	}

	UpdateData(FALSE);
}
