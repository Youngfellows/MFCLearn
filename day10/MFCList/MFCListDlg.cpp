
// MFCListDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCList.h"
#include "MFCListDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCListDlg 对话框



CMFCListDlg::CMFCListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCLIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_COMBO, m_combox);
}

BEGIN_MESSAGE_MAP(CMFCListDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO, &CMFCListDlg::OnSelchangeCombo)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CMFCListDlg::OnDblclkList)
END_MESSAGE_MAP()


// CMFCListDlg 消息处理程序

BOOL CMFCListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_combox.AddString("图标");
	m_combox.AddString("小图标");
	m_combox.AddString("列表");
	m_combox.AddString("报表");
	m_combox.SetCurSel(0);

	m_list.InsertColumn(0, "名称", LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, "修改日期", LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, "类型", LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, "大小", LVCFMT_LEFT, 150);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES);//经纬线

	CImageList* pImgList = new CImageList();
	pImgList->Create(IDB_BITMAP1, 24, 1, RGB(255, 255, 255));
	m_list.SetImageList(pImgList, LVSIL_NORMAL);//将图像链表应用在列表控件的图标风格中
	m_list.SetImageList(pImgList, LVSIL_SMALL);//将图像链表应用在列表控件的其他风格中
	ShowFile("c:");
	//TestData();//测试数据
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

/*
* 显示文件
*/
void CMFCListDlg::ShowFile(CString path)
{
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//文件搜索对象
	BOOL goFind = find.FindFile(strPath);//
	int i = 0;
	while (goFind)
	{
		goFind = find.FindNextFile();//找到当前文件，将文件信息保存find对象的成员变量中
		CString filename = find.GetFileName();
		CString* filepath = new CString();//在堆内存保存信息
		*filepath = find.GetFilePath();
		if (find.IsDirectory())
		{
			m_list.InsertItem(i, filename, 0);
			m_list.SetItemData(i, (DWORD)filepath);
		}
		else {
			m_list.InsertItem(i, filename, 1);
		}
		i++;
	}
	find.Close();
}

void CMFCListDlg::TestData()
{
	m_list.InsertItem(0, "目录", 0);
	m_list.SetItemText(0, 1, "2023.8.23");
	m_list.SetItemText(0, 2, "Dir");
	m_list.SetItemText(0, 3, "3M");

	m_list.InsertItem(1, "文件", 1);
	m_list.SetItemText(1, 1, "2024.7.18");
	m_list.SetItemText(1, 2, "File");
	m_list.SetItemText(1, 3, "2M");
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*选这项发生变化*/
void CMFCListDlg::OnSelchangeCombo()
{
	int nSel = m_combox.GetCurSel();
	switch (nSel)
	{
	case 0://图标
		m_list.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_REPORT, LVS_ICON);
		break;
	case 1://小图标
		m_list.ModifyStyle(LVS_LIST | LVS_REPORT | LVS_ICON, LVS_SMALLICON);
		break;
	case 2://列表
		m_list.ModifyStyle(LVS_REPORT | LVS_ICON | LVS_SMALLICON, LVS_LIST);
		break;
	case 3://报表
		m_list.ModifyStyle(LVS_LIST | LVS_ICON | LVS_SMALLICON, LVS_REPORT);
		break;
	default:
		break;
	}
}

/*
* 双击列表项
*/
void CMFCListDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;
	DWORD nData = m_list.GetItemData(pNMItemActivate->iItem);//双击选项
	CString* filepath = (CString*)nData;
	if (filepath != NULL)
	{
		ShowFile(*filepath);
		//AfxMessageBox(*filepath);
	}
}
