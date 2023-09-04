
// MFCCtrl3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCCtrl3.h"
#include "MFCCtrl3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtrl3Dlg 对话框



CMFCCtrl3Dlg::CMFCCtrl3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCTRL3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCtrl3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SIMPLE, m_simple);
	DDX_Control(pDX, IDC_DROPLIST, m_droplist);
	DDX_Control(pDX, IDC_DROPDOWN, m_dropdown);
}

BEGIN_MESSAGE_MAP(CMFCCtrl3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR, &CMFCCtrl3Dlg::OnClickedClear)
	ON_BN_CLICKED(IDC_DEL, &CMFCCtrl3Dlg::OnClickedDel)
	ON_BN_CLICKED(IDC_TEXT, &CMFCCtrl3Dlg::OnClickedText)
	ON_BN_CLICKED(IDC_DATA, &CMFCCtrl3Dlg::OnClickedData)
	ON_CBN_SELCHANGE(IDC_SIMPLE, &CMFCCtrl3Dlg::OnSelchangeSimple)//选择项发生改变
	ON_CBN_EDITCHANGE(IDC_SIMPLE, &CMFCCtrl3Dlg::OnEditchangeSimple)//文本内容发生变化
END_MESSAGE_MAP()


// CMFCCtrl3Dlg 消息处理程序

BOOL CMFCCtrl3Dlg::OnInitDialog()
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
		m_simple.AddString(szItem);
		m_simple.SetItemData(i, 1000 + i);//设置选择项附加数据

		m_dropdown.AddString(szItem);
		m_droplist.AddString(szItem);
	}
	m_simple.SetCurSel(88);
	m_dropdown.SetCurSel(92);
	m_droplist.SetCurSel(99);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCtrl3Dlg::OnPaint()
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
HCURSOR CMFCCtrl3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCtrl3Dlg::OnClickedClear()
{
	m_simple.ResetContent();
	m_dropdown.ResetContent();
	m_droplist.ResetContent();
}


void CMFCCtrl3Dlg::OnClickedDel()
{
	m_simple.DeleteString(m_simple.GetCurSel());
	m_dropdown.DeleteString(m_dropdown.GetCurSel());
	m_droplist.DeleteString(m_droplist.GetCurSel());
}


void CMFCCtrl3Dlg::OnClickedText()
{
	//获取选项的文本内容
	CString str;
	m_simple.GetLBText(m_simple.GetCurSel(), str);
	AfxMessageBox(str);
}


void CMFCCtrl3Dlg::OnClickedData()
{
	DWORD nData = m_simple.GetItemData(m_simple.GetCurSel());
	CString strData;
	strData.Format("附加数据:%d", nData);
	AfxMessageBox(strData);
}


void CMFCCtrl3Dlg::OnSelchangeSimple()
{
	int nSel = m_simple.GetCurSel();
	m_dropdown.SetCurSel(nSel);
	m_droplist.SetCurSel(nSel);
}


void CMFCCtrl3Dlg::OnEditchangeSimple()
{
	CString str;
	m_simple.GetWindowText(str);
	AfxMessageBox(str);
}
