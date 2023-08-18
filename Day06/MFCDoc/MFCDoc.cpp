#include<afxwin.h>
#include<afxext.h>
#include "resource.h"

/*文档类*/
class CMyDoc : public CDocument {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	afx_msg void OnOpen();
public:
	CString str1;//数据1
	CString str2;//数据2
};
BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
	ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_OPEN, OnOpen)
END_MESSAGE_MAP()

void CMyDoc::OnNew()
{
	AfxMessageBox("文档类处理了ON_COMANDX的OnNew消息");
	this->str1 = "From newButton window";//接收到的数据
	this->str2 = "I am a student";
	this->UpdateAllViews(NULL);//刷新和这个文档类对象（this）关联的所有视图窗口
}

void CMyDoc::OnOpen()
{
	AfxMessageBox("文档类处理了ON_COMANDX的OnOpen消息");
	this->str1 = "From openButton window";//接收到的数据
	this->str2 = "I am a teacher";
	//this->UpdateAllViews(NULL);//刷新和这个文档类对象（this）关联的所有视图窗口
	POSITION pos = this->GetFirstViewPosition(); //GetFirstXXXPosition
	CView* pView = this->GetNextView(pos);//GetNextXXX
	this->UpdateAllViews(pView);//刷新和这个文档类对象（this）关联的除了pView指向的视图窗口
}


/*视图窗口类*/
class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)//动态创建机制
		DECLARE_MESSAGE_MAP(CMyView)//消息映射机制

public:
	virtual void OnDraw(CDC* pDC) override;
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();
	afx_msg void OnOpen();
};
IMPLEMENT_DYNCREATE(CMyView, CView)
BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_CREATE()
	//ON_COMMAND(ID_NEW, OnNew)
	//ON_COMMAND(ID_OPEN, OnOpen)
END_MESSAGE_MAP()

void CMyView::OnNew()
{
	AfxMessageBox("视图类处理了ON_COMANDX的OnNew消息");
}

void CMyView::OnOpen()
{
	AfxMessageBox("视图类处理了ON_COMANDX的OnOpen消息");
}

void CMyView::OnDraw(CDC* pDC)
{
	//获取文档类对象
	CMyDoc* pDoc = (CMyDoc*)this->m_pDocument;
	pDC->TextOut(100, 100, pDoc->str1);
	pDC->TextOut(100, 130, pDoc->str2);
}

int CMyView::OnCreate(LPCREATESTRUCT pcs)
{
	return CView::OnCreate(pcs); //将文档类对象和视图类对象建立关联关系。
}

/*框架窗口类*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP(CMyFrameWnd)//消息映射机制
public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnPaint();
	afx_msg void OnNew();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);//窗口拆分

public:
	CSplitterWnd split;//不规则框架窗口
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	//ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("框架类处理了ON_COMANDX的OnNew消息");
}

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//创建两个视图窗口
	split.CreateStatic(this, 1, 2);
	split.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(100, 100), pContext);
	split.CreateView(0, 1, pContext->m_pNewViewClass, CSize(100, 100), pContext);
	this->m_pViewActive = (CView*)split.GetPane(0, 0);//获取第1个视图窗口并设置当前活动视图窗口
	return TRUE;
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	return CFrameWnd::OnCreate(pcs);//动态创建视图类对象，并创建视图窗口
}

void CMyFrameWnd::OnPaint()
{
	const char* pszText = "我是框架窗口客户区";
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}


/*应用程序类*/
class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	//ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyWinApp::OnNew()
{
	AfxMessageBox("应用程序类处理了ON_COMANDX的OnNew消息");
}

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	CMyDoc* pDoc = new CMyDoc();

	CCreateContext cct;
	cct.m_pCurrentDoc = pDoc;//文档对象地址
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);//&CMyView::classCMyView

	//pFrame->Create(NULL, "MFCDoc");
	pFrame->LoadFrame(IDR_MENU1, WS_OVERLAPPEDWINDOW, NULL, &cct);

	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//爆破点

