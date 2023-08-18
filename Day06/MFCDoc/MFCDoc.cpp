#include<afxwin.h>
#include<afxext.h>
#include "resource.h"

/*�ĵ���*/
class CMyDoc : public CDocument {
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNew();
	afx_msg void OnOpen();
public:
	CString str1;//����1
	CString str2;//����2
};
BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
	ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_OPEN, OnOpen)
END_MESSAGE_MAP()

void CMyDoc::OnNew()
{
	AfxMessageBox("�ĵ��ദ����ON_COMANDX��OnNew��Ϣ");
	this->str1 = "From newButton window";//���յ�������
	this->str2 = "I am a student";
	this->UpdateAllViews(NULL);//ˢ�º�����ĵ������this��������������ͼ����
}

void CMyDoc::OnOpen()
{
	AfxMessageBox("�ĵ��ദ����ON_COMANDX��OnOpen��Ϣ");
	this->str1 = "From openButton window";//���յ�������
	this->str2 = "I am a teacher";
	//this->UpdateAllViews(NULL);//ˢ�º�����ĵ������this��������������ͼ����
	POSITION pos = this->GetFirstViewPosition(); //GetFirstXXXPosition
	CView* pView = this->GetNextView(pos);//GetNextXXX
	this->UpdateAllViews(pView);//ˢ�º�����ĵ������this�������ĳ���pViewָ�����ͼ����
}


/*��ͼ������*/
class CMyView : public CView {
	DECLARE_DYNCREATE(CMyView)//��̬��������
		DECLARE_MESSAGE_MAP(CMyView)//��Ϣӳ�����

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
	AfxMessageBox("��ͼ�ദ����ON_COMANDX��OnNew��Ϣ");
}

void CMyView::OnOpen()
{
	AfxMessageBox("��ͼ�ദ����ON_COMANDX��OnOpen��Ϣ");
}

void CMyView::OnDraw(CDC* pDC)
{
	//��ȡ�ĵ������
	CMyDoc* pDoc = (CMyDoc*)this->m_pDocument;
	pDC->TextOut(100, 100, pDoc->str1);
	pDC->TextOut(100, 130, pDoc->str2);
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
	afx_msg void OnNew();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);//���ڲ��

public:
	CSplitterWnd split;//�������ܴ���
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	//ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("����ദ����ON_COMANDX��OnNew��Ϣ");
}

BOOL CMyFrameWnd::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	//����������ͼ����
	split.CreateStatic(this, 1, 2);
	split.CreateView(0, 0, RUNTIME_CLASS(CMyView), CSize(100, 100), pContext);
	split.CreateView(0, 1, pContext->m_pNewViewClass, CSize(100, 100), pContext);
	this->m_pViewActive = (CView*)split.GetPane(0, 0);//��ȡ��1����ͼ���ڲ����õ�ǰ���ͼ����
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
	AfxMessageBox("Ӧ�ó����ദ����ON_COMANDX��OnNew��Ϣ");
}

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

