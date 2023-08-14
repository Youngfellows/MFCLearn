#include<afxwin.h>
#include"resource.h"

/*框架类*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()//消息映射机制处理消息

public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();//处理菜单的点击事件
	afx_msg void OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i);//设置菜单项状态
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pt);//右键菜单

public:
	CMenu menu;
};

//消息映射机制处理消息
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	//ON_COMMAND(ID_NEW, OnNew)
	ON_WM_INITMENUPOPUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

//方式2:加载菜单
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	menu.LoadMenu(IDR_MENU1);
	//this->SetMenu(&menu);
	::SetMenu(this->m_hWnd, menu.m_hMenu);
	return CFrameWnd::OnCreate(pcs);
}

//处理菜单的点击事件
void CMyFrameWnd::OnNew()
{
	AfxMessageBox("框架类处理了新建菜单项被点击");
}

//设置菜单项状态
void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i)
{
	//pPopup->CheckMenuItem(ID_NEW, MF_CHECKED);
	::CheckMenuItem(pPopup->m_hMenu, ID_NEW, MF_CHECKED);
}

//右键菜单
void CMyFrameWnd::OnContextMenu(CWnd* pWnd, CPoint pt)
{
	//CMenu* pPopup = menu.GetSubMenu(0);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, this);

	HMENU hPopup = ::GetSubMenu(menu.m_hMenu, 0);
	::TrackPopupMenu(hPopup, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, this->m_hWnd, NULL);
}

/*应用程序类*/
class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()//消息映射机制处理消息

public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};

//消息映射机制处理消息
BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCMenu");
	//方式1:加载菜单
	//pFrame->Create(NULL, "MFCMenu", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, (char*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

//处理菜单的点击事件
void CMyWinApp::OnNew()
{
	AfxMessageBox("应用程序类处理了新建菜单项被点击");
}

/*爆破点*/
CMyWinApp theApp;