
// TestClasseBddDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "TestClasseBdd.h"
#include "TestClasseBddDlg.h"
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


// boîte de dialogue CTestClasseBddDlg



CTestClasseBddDlg::CTestClasseBddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTCLASSEBDD_DIALOG, pParent)
	, m_sConnexion(_T(""))
	, m_sUpdate(_T(""))
	, m_sLire(_T(""))
	//, m_sUpdate(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestClasseBddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONNEXION, m_sConnexion);
	//  DDX_Text(pDX, IDC_LIRE, m_sUpdate);
	DDX_Text(pDX, IDC_LIRE, m_sLire);
	DDX_Text(pDX, IDC_UPDATE, m_sUpdate);
}

BEGIN_MESSAGE_MAP(CTestClasseBddDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNEC1, &CTestClasseBddDlg::OnBnClickedConnec1)
	ON_BN_CLICKED(IDC_CONNEC2, &CTestClasseBddDlg::OnBnClickedConnec2)
	ON_BN_CLICKED(IDC_UPD1, &CTestClasseBddDlg::OnBnClickedUpd1)
	ON_BN_CLICKED(IDC_UPD2, &CTestClasseBddDlg::OnBnClickedUpd2)
	ON_BN_CLICKED(IDC_LIRE1, &CTestClasseBddDlg::OnBnClickedLire1)
	ON_BN_CLICKED(IDC_LIRE2, &CTestClasseBddDlg::OnBnClickedLire2)
END_MESSAGE_MAP()


// gestionnaires de messages pour CTestClasseBddDlg

BOOL CTestClasseBddDlg::OnInitDialog()
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
	connect = false;

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CTestClasseBddDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestClasseBddDlg::OnPaint()
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
HCURSOR CTestClasseBddDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestClasseBddDlg::OnBnClickedConnec1()
{
	bool X;
	X = maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);

	if (X == true)
		m_sConnexion.Format(L"connexion reussi");
	else
		m_sConnexion.Format(L"connexion échouer");

	maBdd.Close();

	UpdateData(FALSE);
}


void CTestClasseBddDlg::OnBnClickedConnec2()
{
	bool X;
	X = maBdd.Connect("Ours", "Brun", DATABASE, ADRESSE, 3306);

	if (X == true)
	{
		m_sConnexion.Format(L"connexion reussi");
		connect = true;
	}
		
	else
	{
		m_sConnexion.Format(L"connexion échouer");
		connect = false;
	}
		

	maBdd.Close();

	UpdateData(FALSE);
}


void CTestClasseBddDlg::OnBnClickedUpd1()
{
	bool X;

	maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);
	X = maBdd.WriteRequest("UPDATE `bdd`.`nom` SET `NOM_Nom` ='Test',`Nom_Prenom` ='Test' WHERE NOM_Nom = 'Test' AND NOM_Prenom = 'Test'");

	if (X)
		m_sUpdate.Format(L"mise a jour réussi");
	else
		m_sUpdate.Format(L"mise a jour échouer");

	maBdd.Close();

	UpdateData(FALSE);
}


void CTestClasseBddDlg::OnBnClickedUpd2()
{
	bool X;

	maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);
	X = maBdd.WriteRequest("UPDATE `bdd`.`nom` SET `NOM_Nom` ='Test',`Nom_Prenom` ='Test' WHERE NOM_Nom = 'Ours' AND NOM_Prenom = 'Brun'");

	if (X)
		m_sUpdate.Format(L"mise a jour réussi");
	else
		m_sUpdate.Format(L"mise a jour échouer");

	maBdd.Close();

	UpdateData(FALSE);
}


void CTestClasseBddDlg::OnBnClickedLire1()
{
	vector<vector<CString>> test;

	maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);
	test = maBdd.ReadRequest("SELECT NOM_Id FROM `nom` WHERE NOM_Nom='Carly' AND NOM_Prenom = 'Bruno'");

	if (test.size() > 0)
		m_sLire.Format(L"Résultat trouver");
	else
		m_sLire.Format(L"Résultat non trouver");

	UpdateData(FALSE);
}


void CTestClasseBddDlg::OnBnClickedLire2()
{
	vector<vector<CString>> test;

	maBdd.Connect(ID, PASSWORD, DATABASE, ADRESSE, 3306);
	test = maBdd.ReadRequest("SELECT NOM_Id FROM `nom` WHERE NOM_Nom='Ours' AND NOM_Prenom = 'Brun'");

	if (test.size() > 0)
		m_sLire.Format(L"Résultat trouver");
	else
		m_sLire.Format(L"Résultat non trouver");

	UpdateData(FALSE);
}
