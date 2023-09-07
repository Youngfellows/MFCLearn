
// MFCTreeDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCTree.h"
#include "MFCTreeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTreeDlg 对话框



CMFCTreeDlg::CMFCTreeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTREE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_ST, m_st);
}

BEGIN_MESSAGE_MAP(CMFCTreeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEL, &CMFCTreeDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_TEXT, &CMFCTreeDlg::OnBnClickedText)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CMFCTreeDlg::OnSelchangedTree)
END_MESSAGE_MAP()


// CMFCTreeDlg 消息处理程序

BOOL CMFCTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CImageList* pImgList = new CImageList();
	pImgList->Create(IDB_BITMAP1, 12, 1, RGB(255, 255, 255));
	m_tree.SetImageList(pImgList, LVSIL_NORMAL);

	HTREEITEM nRoot = m_tree.InsertItem("广东省", 0, 1, NULL);
	CString* data = new CString();
	*data = "广东省";
	m_tree.SetItemData(nRoot, (DWORD_PTR)data);

	HTREEITEM nGZ = m_tree.InsertItem("广州市", 2, 3, nRoot);
	data = new CString();
	*data = "广州南站";
	m_tree.SetItemData(nGZ, (DWORD_PTR)data);

	HTREEITEM nSZ = m_tree.InsertItem("深圳市", 2, 3, nRoot);
	data = new CString();
	*data = "深圳北站";
	m_tree.SetItemData(nSZ, (DWORD_PTR)data);

	HTREEITEM nCZ = m_tree.InsertItem("潮州市", 2, 3, nRoot);
	data = new CString();
	*data = "汕头站";
	m_tree.SetItemData(nCZ, (DWORD_PTR)data);


	HTREEITEM nHZ = m_tree.InsertItem("惠州市", 2, 3, nRoot);
	data = new CString();
	*data = "惠州南站";
	m_tree.SetItemData(nHZ, (DWORD_PTR)data);
	m_tree.SetItemHeight(50);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTreeDlg::OnPaint()
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
HCURSOR CMFCTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTreeDlg::OnBnClickedDel()
{
	m_tree.DeleteItem(m_tree.GetSelectedItem());//删除选择项
}


void CMFCTreeDlg::OnBnClickedText()
{
	CString szText = m_tree.GetItemText(m_tree.GetSelectedItem());//获取选项文本
	DWORD_PTR nData = m_tree.GetItemData(m_tree.GetSelectedItem());//获取选项附加数据
	CString* szData = (CString*)nData;
	if (szData != NULL)
	{
		szText += "--";
		szText += *szData;
	}
	m_st.SetWindowText(szText);
	AfxMessageBox(szText);
}


void CMFCTreeDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	DWORD_PTR nData = m_tree.GetItemData(m_tree.GetSelectedItem());
	CString* szText = (CString*)nData;
	if (szText != NULL)
	{
		m_st.SetWindowText(*szText);
	}

	*pResult = 0;
}
