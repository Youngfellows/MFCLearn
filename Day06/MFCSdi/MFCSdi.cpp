#include<afxwin.h>
#include "resource.h"

/*文档类*/
class CMyDoc : public CDocument {
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

/*视图窗口类*/
class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* pDC);
};
IMPLEMENT_DYNCREATE(CMyView, CView)

void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(100, 100, "我是视图窗口");
}


/*框架类*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)

/*应用程序类*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	CSingleDocTemplate* pTemplate = new CSingleDocTemplate(IDR_MENU1, RUNTIME_CLASS(CMyDoc), RUNTIME_CLASS(CMyFrameWnd), RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);
	OnFileNew();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//爆破点

