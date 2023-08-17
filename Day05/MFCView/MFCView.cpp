#include<afxwin.h>
#include "resource.h"

/*��ͼ������*/
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
	//ON_WM_PAINT()//�����ͼ��Ϣ
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
	AfxMessageBox("��ͼ�ദ����WM_COMMAND��OnNew��Ϣ");
}

void CMyView::OnOpen()
{
	AfxMessageBox("��ͼ�ദ����WM_COMMAND��OnOpen��Ϣ");
}

void CMyView::OnClose()
{
	AfxMessageBox("��ͼ�ദ����WM_COMMAND��OnClose��Ϣ");
}


/*��ܴ�����*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()//��Ϣӳ�����
public:
	afx_msg void OnPaint();//�����ͼ��Ϣ
	afx_msg int OnCreate(LPCREATESTRUCT pcs);//�����ܵ�create��Ϣ
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("����ദ����WM_COMMAND��OnNew��Ϣ");
}

void CMyFrameWnd::OnPaint()
{
	const char* pszText = "���ǿ�ܴ��ڿͻ���";
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	::TextOut(hdc, 100, 100, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs) {
	//�����ͼ���ڵ���ܴ���
	CMyView* pView = new CMyView();
	pView->Create(NULL, "MFCView", WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(0, 0, 200, 200), this, AFX_IDW_PANE_FIRST);
	this->m_pViewActive = pView;
	return CFrameWnd::OnCreate(pcs);
}

/*Ӧ�ó�����*/
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
	AfxMessageBox("Ӧ�ó����ദ����WM_COMMAND��OnNew��Ϣ");
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

CMyWinApp theApp;//���Ƶ�