
// MFCCtrl1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCCtrl1.h"
#include "MFCCtrl1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtrl1Dlg 对话框



CMFCCtrl1Dlg::CMFCCtrl1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCTRL1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCtrl1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_VLIST, m_vlistbox);
	DDX_Control(pDX, IDC_HLIST, m_hlistbox);
	DDX_Control(pDX, IDC_ST1, m_st1);
	DDX_Control(pDX, IDC_ST2, m_st2);
}

BEGIN_MESSAGE_MAP(CMFCCtrl1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR, &CMFCCtrl1Dlg::OnClickedClear)
	ON_BN_CLICKED(IDC_DEL, &CMFCCtrl1Dlg::OnClickedDel)
	ON_BN_CLICKED(IDC_TEXT, &CMFCCtrl1Dlg::OnClickedText)
	ON_BN_CLICKED(IDC_DATA, &CMFCCtrl1Dlg::OnClickedData)
	ON_LBN_SELCHANGE(IDC_VLIST, &CMFCCtrl1Dlg::OnSelchangeVlist)
END_MESSAGE_MAP()


// CMFCCtrl1Dlg 消息处理程序

BOOL CMFCCtrl1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	for (int i = 0; i < 100; i++)
	{
		char szItem[256];
		sprintf_s(szItem, "Item%d", i + 1);
		m_vlistbox.AddString(szItem);
		m_vlistbox.SetItemData(i, 1000 + i);//添加附加数据
		m_hlistbox.AddString(szItem);
	}

	//设置默认选择项
	m_vlistbox.SetCurSel(33);
	m_hlistbox.SetSel(2, TRUE);
	//m_hlistbox.SetCurSel(2);//不生效

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCtrl1Dlg::OnPaint()
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
HCURSOR CMFCCtrl1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCtrl1Dlg::OnClickedClear()
{
	m_vlistbox.ResetContent();
	m_hlistbox.ResetContent();
}


void CMFCCtrl1Dlg::OnClickedDel()
{
	int nSel = m_vlistbox.GetCurSel();//获取选择项索引
	m_vlistbox.DeleteString(nSel);

	nSel = m_hlistbox.GetCurSel();
	m_hlistbox.DeleteString(nSel);
}


void CMFCCtrl1Dlg::OnClickedText()
{
	CString str;
	m_vlistbox.GetText(m_vlistbox.GetCurSel(), str);
	AfxMessageBox(str);
}


void CMFCCtrl1Dlg::OnClickedData()
{
	DWORD nData = m_vlistbox.GetItemData(m_vlistbox.GetCurSel());
	CString str;
	str.Format("附加数据:%d", nData);
	AfxMessageBox(str);
}

/*
* 选项发生改变
*/
void CMFCCtrl1Dlg::OnSelchangeVlist()
{
	int nSel = m_vlistbox.GetCurSel();
	CString str;
	m_vlistbox.GetText(nSel, str);
	AfxMessageBox(str);

	m_hlistbox.SetSel(nSel, TRUE);//同步
}
