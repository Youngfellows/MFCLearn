
// MFCCtrl2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCtrl2.h"
#include "MFCCtrl2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtrl2Dlg dialog




CMFCCtrl2Dlg::CMFCCtrl2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCCtrl2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCtrl2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Control(pDX, IDC_BUTTON1, m_btn);
	DDX_Control(pDX, IDC_RADIO1, m_r1);
	DDX_Control(pDX, IDC_RADIO2, m_r2);
	DDX_Control(pDX, IDC_GROUP, m_group);
	DDX_Control(pDX, IDC_ST, m_st);
	DDX_Control(pDX, IDC_PS, m_ps);
	DDX_Control(pDX, IDC_PS2, m_ps2);
}

BEGIN_MESSAGE_MAP(CMFCCtrl2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCCtrl2Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCCtrl2Dlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCCtrl2Dlg::OnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCCtrl2Dlg::OnClickedRadio2)
END_MESSAGE_MAP()


// CMFCCtrl2Dlg message handlers

BOOL CMFCCtrl2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_check.SetCheck(TRUE);
	m_r1.SetCheck(TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCtrl2Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCtrl2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCtrl2Dlg::OnClickedButton1()
{
	/*
	if( m_check.GetCheck() )
		m_check.SetCheck( FALSE );
	else
		m_check.SetCheck( TRUE );*/
	m_check.SetCheck(!m_check.GetCheck());
	m_st.SetWindowText("hello");
	m_ps.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2)));
	m_ps2.SetBitmap(::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));

}

void CMFCCtrl2Dlg::OnClickedCheck1()
{
	int nState = m_check.GetCheck();
	CString sState;
	sState.Format("%d", nState);
	m_btn.SetWindowText(sState);
}


void CMFCCtrl2Dlg::OnClickedRadio1()//ÄÐ
{
	m_r1.SetCheck(TRUE);
	m_r2.SetCheck(FALSE);
}


void CMFCCtrl2Dlg::OnClickedRadio2()//Å®
{
	m_r2.SetCheck(TRUE);
	m_r1.SetCheck(FALSE);
}
