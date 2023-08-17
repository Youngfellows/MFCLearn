#include<afxwin.h>
#include "resource.h"

/*视图窗口类*/
class CMyView : public CView {
	DECLARE_MESSAGE_MAP()

public:
	virtual void OnDraw(CDC* pDC) override;
	afx_msg void OnPaint();
	afx_msg void OnNew();
	afx_msg void OnOpen();
	afx_msg void OnClose();
};
BEGIN_MESSAGE_MAP(CMyView, CView)
	//ON_WM_PAINT()//处理绘图消息
	//ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_OPEN, OnOpen)
	ON_COMMAND(ID_CLOSE, OnClose)
END_MESSAGE_MAP()

void CMyView::OnPaint()
{
	const char* pszText = " CMyView::OnPaint";
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}

void CMyView::OnDraw(CDC* pDC) {
	const char* pszText = "CMyView::OnDraw";
	pDC->TextOut(100, 100, pszText);
}

void CMyView::OnNew()
{
	AfxMessageBox("视图类处理了WM_COMMAND的OnNew消息");
}

void CMyView::OnOpen()
{
	AfxMessageBox("视图类处理了WM_COMMAND的OnOpen消息");
}

void CMyView::OnClose()
{
	AfxMessageBox("视图类处理了WM_COMMAND的OnClose消息");
}


/*框架窗口类*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()//消息映射机制
public:
	afx_msg void OnPaint();//处理绘图消息
	afx_msg int OnCreate(LPCREATESTRUCT pcs);//处理框架的create消息
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("框架类处理了WM_COMMAND的OnNew消息");
}

void CMyFrameWnd::OnPaint()
{
	const char* pszText = "我是框架窗口客户区";
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	//添加视图窗口到框架窗口
	CMyView* pView = new CMyView();
	pView->Create(NULL, "MFCView", WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(0, 0, 200, 200), this, AFX_IDW_PANE_FIRST);
	this->m_pViewActive = pView;
	return CFrameWnd::OnCreate(pcs);
}

/*应用程序类*/
class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyWinApp::OnNew()
{
	AfxMessageBox("应用程序类处理了WM_COMMAND的OnNew消息");
}

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCView", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, (CHAR*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//爆破点