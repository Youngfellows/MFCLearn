
// MFCListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCList.h"
#include "MFCListDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCListDlg dialog




CMFCListDlg::CMFCListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMFCListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCListDlg::OnSelchangeCombo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CMFCListDlg::OnDblclkList1)
END_MESSAGE_MAP()


// CMFCListDlg message handlers

BOOL CMFCListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_combox.AddString( "图标" );
	m_combox.AddString( "小图标" );
	m_combox.AddString( "列表" );
	m_combox.AddString( "报表" );
	m_combox.SetCurSel( 0 );

	m_list.InsertColumn( 0, "名称", LVCFMT_LEFT, 150 );
	m_list.InsertColumn( 1, "修改日期", LVCFMT_LEFT, 150 );
	m_list.InsertColumn( 2, "类型", LVCFMT_LEFT, 150 );
	m_list.InsertColumn( 3, "大小", LVCFMT_LEFT, 150 );
	m_list.SetExtendedStyle( LVS_EX_GRIDLINES );//经纬线

	CImageList* pImgLst = new CImageList;
	pImgLst->Create( IDB_BITMAP1, 24, 1, RGB(255,255,255) );

	m_list.SetImageList( pImgLst, LVSIL_NORMAL );//将图像链表应用在列表控件的图标风格中
	m_list.SetImageList( pImgLst, LVSIL_SMALL );//将图像链表应用在列表控件的其他风格中

	ShowFile("c:");
/*//测试数据
	m_list.InsertItem( 0, "目录", 0 );
	m_list.SetItemText( 0, 1, "2100.5.7" );
	m_list.SetItemText( 0, 2, "Dir" );
	m_list.SetItemText( 0, 3, "3M" );

	m_list.InsertItem( 1, "文件", 1 );
	m_list.SetItemText( 1, 1, "2100.12.17" );
	m_list.SetItemText( 1, 2, "File" );
	m_list.SetItemText( 1, 3, "13K" );*/

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CMFCListDlg::ShowFile( CString path ){
	m_list.DeleteAllItems( );
	CString strPath = path;
	strPath += "/*.*";   
	CFileFind find;//文件搜索类对象
	BOOL goFind = find.FindFile( strPath ); //开启查找
	int i = 0;
	while( goFind ){
		goFind = find.FindNextFile( );//找到当前文件，将文件信息保存find对象的成员变量中
		CString filename = find.GetFileName( );	
		CString *filepath = new CString;
		*filepath = find.GetFilePath();
		if( find.IsDirectory() ){
			m_list.InsertItem( i, filename, 0 );
			m_list.SetItemData( i, (DWORD)filepath); 
		}else{
			m_list.InsertItem( i, filename, 1 );
		}
		i++;
	}
	find.Close( );
	
}
void CMFCListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCListDlg::OnPaint()
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
HCURSOR CMFCListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCListDlg::OnSelchangeCombo1()
{
	switch( m_combox.GetCurSel() ){
	case 0://图标
		m_list.ModifyStyle( LVS_SMALLICON|LVS_LIST|LVS_REPORT, LVS_ICON );
		break;
	case 1://小图标
		m_list.ModifyStyle( LVS_ICON|LVS_LIST|LVS_REPORT, LVS_SMALLICON );
		break;
	case 2://列表
		m_list.ModifyStyle( LVS_ICON|LVS_SMALLICON|LVS_REPORT, LVS_LIST );
		break;
	case 3://报表
		m_list.ModifyStyle( LVS_ICON|LVS_LIST|LVS_SMALLICON, LVS_REPORT );
		break;
	}
}


void CMFCListDlg::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	DWORD nData = m_list.GetItemData( pNMItemActivate->iItem );//双击选项
	CString* filepath = (CString*)nData;
	if( filepath != NULL )
		ShowFile( *filepath );
}
