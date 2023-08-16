
// MFCCtrl3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCtrl3.h"
#include "MFCCtrl3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtrl3Dlg dialog




CMFCCtrl3Dlg::CMFCCtrl3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCCtrl3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCtrl3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DROPDOWN, m_dropdown);
	DDX_Control(pDX, IDC_DROPLIST, m_droplist);
	DDX_Control(pDX, IDC_SIMPLE, m_simple);
}

BEGIN_MESSAGE_MAP(CMFCCtrl3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR, &CMFCCtrl3Dlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_DEL, &CMFCCtrl3Dlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_TEXT, &CMFCCtrl3Dlg::OnBnClickedText)
	ON_BN_CLICKED(IDC_DATA, &CMFCCtrl3Dlg::OnBnClickedData)
	ON_CBN_SELCHANGE(IDC_SIMPLE, &CMFCCtrl3Dlg::OnSelchangeSimple)
	ON_CBN_EDITCHANGE(IDC_SIMPLE, &CMFCCtrl3Dlg::OnEditchangeSimple)
END_MESSAGE_MAP()


// CMFCCtrl3Dlg message handlers

BOOL CMFCCtrl3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	for( int i=0; i<100; i++ ){
		char szItem[256];
		sprintf(szItem, "Item%d", i);
		m_simple.AddString( szItem );//追加选项
		m_simple.SetItemData( i, 1000+i );

		m_dropdown.AddString( szItem );
		m_droplist.AddString( szItem );
	}
	m_simple.SetCurSel( 99 );
	m_dropdown.SetCurSel( 99 );
	m_droplist.SetCurSel( 99 );
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCtrl3Dlg::OnPaint()
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
HCURSOR CMFCCtrl3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCtrl3Dlg::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	m_simple.ResetContent( );
	m_dropdown.ResetContent( );
	m_droplist.ResetContent( );
}

void CMFCCtrl3Dlg::OnBnClickedDel()
{
	m_simple.DeleteString( m_simple.GetCurSel() );
	m_dropdown.DeleteString( m_dropdown.GetCurSel() );
	m_droplist.DeleteString( m_droplist.GetCurSel() );
}


void CMFCCtrl3Dlg::OnBnClickedText()
{
	//获取选项的文本内容
	CString str;
	m_simple.GetLBText( m_simple.GetCurSel(), str );
	AfxMessageBox( str );
}


void CMFCCtrl3Dlg::OnBnClickedData()
{
	DWORD nData = m_simple.GetItemData( m_simple.GetCurSel() );
	CString strData;
	strData.Format( "附加数据:%d", nData );
	AfxMessageBox( strData );
}


void CMFCCtrl3Dlg::OnSelchangeSimple()
{
	int nSel = m_simple.GetCurSel();
	m_dropdown.SetCurSel( nSel );
	m_droplist.SetCurSel( nSel );
}


void CMFCCtrl3Dlg::OnEditchangeSimple()
{
	AfxMessageBox( "内容被修改" );
}
