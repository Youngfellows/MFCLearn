#include<afxwin.h>
#include<afxext.h>
#include "resource.h"

/*框架类*/
class CMyFrameWnd :public CFrameWnd {
	DECLARE_MESSAGE_MAP()//消息映射机制
public:
	afx_msg void OnNew();
	afx_msg void OnSave();
	afx_msg void OnSet();
	afx_msg int OnCreate(LPCREATESTRUCT pcs);

public:
	CToolBar toolbar;
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_SAVE, OnSave)
	ON_COMMAND(ID_SET, OnSet)
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("新建菜单项被点击");
}

void CMyFrameWnd::OnSet()
{
	AfxMessageBox("蓝色工具按钮被点击了");
}

void CMyFrameWnd::OnSave()
{
	AfxMessageBox("绿色工具按钮被点击了");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	//加载工具栏
	toolbar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);
	this->EnableDocking(CBRS_ALIGN_ANY);
	this->DockControlBar(&toolbar, AFX_IDW_DOCKBAR_BOTTOM);
	return CFrameWnd::OnCreate(pcs);
}

/*应用程序类*/
class CMyWinApp :public CWinApp {

public:
	virtual BOOL InitInstance() override;
};

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	//pFrame->Create(NULL, "MFCToolBar");
	//加载菜单栏
	pFrame->Create(NULL, "MFCToolBar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, (CHAR*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//爆破点