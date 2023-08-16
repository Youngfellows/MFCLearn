
// MFCTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTree.h"
#include "MFCTreeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTreeDlg dialog




CMFCTreeDlg::CMFCTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCTreeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}

BEGIN_MESSAGE_MAP(CMFCTreeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEL, &CMFCTreeDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_TEXT, &CMFCTreeDlg::OnBnClickedText)
END_MESSAGE_MAP()


// CMFCTreeDlg message handlers

BOOL CMFCTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CImageList* pImgLst = new CImageList;
	pImgLst->Create( IDB_BITMAP1, 12, 1, RGB(255,255,255));

	m_tree.SetImageList( pImgLst, LVSIL_NORMAL );

	HTREEITEM nRoot = m_tree.InsertItem( "达内集团", 0, 1, NULL );
	m_tree.InsertItem( "中关村中心", 2, 3, nRoot );
	m_tree.InsertItem( "亚运村中心", 2, 3, nRoot );
	m_tree.InsertItem( "天坛中心", 2, 3, nRoot );
	m_tree.SetItemHeight( 50 );
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCTreeDlg::OnPaint()
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
HCURSOR CMFCTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCTreeDlg::OnBnClickedDel()
{
	m_tree.DeleteItem(m_tree.GetSelectedItem( ));
}


void CMFCTreeDlg::OnBnClickedText()
{
	AfxMessageBox( m_tree.GetItemText( m_tree.GetSelectedItem() ) );
}
