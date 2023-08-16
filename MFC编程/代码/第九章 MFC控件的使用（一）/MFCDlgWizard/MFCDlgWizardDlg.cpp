
// MFCDlgWizardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDlgWizard.h"
#include "MFCDlgWizardDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDlgWizardDlg dialog




CMFCDlgWizardDlg::CMFCDlgWizardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDlgWizardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_str = _T("");
}

void CMFCDlgWizardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CMFCDlgWizardDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDlgWizardDlg::OnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCDlgWizardDlg::OnChangeEdit1)
END_MESSAGE_MAP()


// CMFCDlgWizardDlg message handlers

BOOL CMFCDlgWizardDlg::OnInitDialog()//¥¶¿ÌWM_INITDIALOG
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_btn.MoveWindow( 0, 0, 100, 100 );
	m_btn.SetWindowText( "button" );	
//	m_edit.SetWindowText( "hello world" );
	m_str = "hello no world";
	UpdateData( FALSE );
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDlgWizardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDlgWizardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDlgWizardDlg::OnClickedButton1()
{
	// TODO: Add your control notification handler code here
//
	char strEdit[256];
	m_edit.GetWindowText( strEdit, 256 );
	AfxMessageBox( strEdit );
}



void CMFCDlgWizardDlg::OnChangeEdit1()
{
//	char strEdit[256];
//	m_edit.GetWindowText( strEdit, 256 );
	UpdateData( TRUE );//m_str
	m_btn.SetWindowText( m_str );
}
