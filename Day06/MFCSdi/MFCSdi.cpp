#include<afxwin.h>
#include "resource.h"

/*�ĵ���*/
class CMyDoc : public CDocument {
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

/*��ͼ������*/
class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)
public:
	virtual void OnDraw(CDC* pDC);
};
IMPLEMENT_DYNCREATE(CMyView, CView)

void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(100, 100, "������ͼ����");
}


/*�����*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd, CFrameWnd)

/*Ӧ�ó�����*/
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

CMyWinApp theApp;//���Ƶ�

