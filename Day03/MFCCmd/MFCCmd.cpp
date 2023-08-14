#include<afxwin.h>

#define WM_MYMESSAGE WM_USER+1001 //�Զ�����Ϣ����

/*
* Ӧ�ó�������
*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()

public:
	int m_x;
	int m_y;

public:
	int OnCreate(LPCREATESTRUCT pcs);
	void OnPaint();
	void OnMouseMove(UINT, CPoint);
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()//ע��create��Ϣ������
	ON_WM_PAINT()//ע��paint��Ϣ������
	ON_WM_MOUSEMOVE()//ע��mousemove��Ϣ������
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()

/*����CREATE��Ϣ*/
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	AfxMessageBox("WM_CREATE��Ϣ������");
	//�����Զ�����Ϣ
	::PostMessage(this->m_hWnd, WM_MYMESSAGE, 1, 2);
	return CFrameWnd::OnCreate(pcs);
}

/*����Paint��Ϣ*/
void CMyFrameWnd::OnPaint()
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	const char* pszText = "hello world";
	::TextOut(hdc, m_x, m_y, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}

/*����ƶ��¼�*/
void CMyFrameWnd::OnMouseMove(UINT nKey, CPoint pt)
{
	this->m_x = pt.x;
	this->m_y = pt.y;
	::InvalidateRect(this->m_hWnd, NULL, TRUE);//����Paint��Ϣ
}

/*�Զ�����Ϣ����*/
LRESULT CMyFrameWnd::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format("wParam=%d,lParam=%d", wParam, lParam);
	AfxMessageBox(str);
	return 0;
}

/*
* Ӧ�ó�����
*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance() override;//��д�����InitInstance����
};

CMyWinApp theApp;//���Ƶ�

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCCreate");
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
