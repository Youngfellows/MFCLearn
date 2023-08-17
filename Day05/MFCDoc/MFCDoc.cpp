#include<afxwin.h>
#include<afxext.h>
#include "resource.h"

/*�ĵ���*/
class CMyDoc : public CDocument {

};

/*��ͼ������*/
class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)//��̬��������
		DECLARE_MESSAGE_MAP(CMyView)//��Ϣӳ�����

public:
	virtual void OnDraw(CDC* pDC) override;
	afx_msg int OnCreate(LPCREATESTRUCT pcs);

};
IMPLEMENT_DYNCREATE(CMyView, CView)
BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(100, 100, "������ͼ����");
}

int CMyView::OnCreate(LPCREATESTRUCT pcs)
{
	return CView::OnCreate(pcs); //���ĵ���������ͼ�������������ϵ��
}

/*��ܴ�����*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP(CMyFrameWnd)//��Ϣӳ�����
public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnPaint();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);//���ڲ��

public:
	CSplitterWnd split;//�������ܴ���
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//����������ͼ����
	split.CreateStatic(this, 1, 2);
	split.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(100, 100), pContext);
	split.CreateView(0, 1, pContext->m_pNewViewClass, CSize(100, 100), pContext);
	return TRUE;
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	return CFrameWnd::OnCreate(pcs);//��̬������ͼ����󣬲�������ͼ����
}

void CMyFrameWnd::OnPaint()
{
	const char* pszText = "���ǿ�ܴ��ڿͻ���";
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}


/*Ӧ�ó�����*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	CMyDoc* pDoc = new CMyDoc();

	CCreateContext cct;
	cct.m_pCurrentDoc = pDoc;//�ĵ������ַ
	cct.m_pNewViewClass = RUNTIME_CLASS(CMyView);//&CMyView::classCMyView

	//pFrame->Create(NULL, "MFCDoc");
	pFrame->LoadFrame(IDR_MENU1, WS_OVERLAPPEDWINDOW, NULL, &cct);

	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//���Ƶ�

