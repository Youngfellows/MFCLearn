
#include<afxwin.h>

#define WM_MYMESSAGE WM_USER+1001 //自定义消息处理

/*
* 应用程序框架类
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

/*消息映射机制*/
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()//注册create消息处理函数
	ON_WM_PAINT()//注册paint消息处理函数
	ON_WM_MOUSEMOVE()//注册mousemove消息处理函数
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()

/*处理CREATE消息*/
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	AfxMessageBox("WM_CREATE消息被处理");
	//发送自定义消息
	::PostMessage(this->m_hWnd, WM_MYMESSAGE, 1, 2);
	return CFrameWnd::OnCreate(pcs);
}

/*处理Paint消息*/
void CMyFrameWnd::OnPaint()
{
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
	const char* pszText = "hello world";
	::TextOut(hdc, m_x, m_y, pszText, strlen(pszText));
	::EndPaint(this->m_hWnd, &ps);
}

/*鼠标移动事件*/
void CMyFrameWnd::OnMouseMove(UINT nKey, CPoint pt)
{
	this->m_x = pt.x;
	this->m_y = pt.y;
	::InvalidateRect(this->m_hWnd, NULL, TRUE);//触发Paint消息
}

/*自定义消息处理*/
LRESULT CMyFrameWnd::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	CString str;
	str.Format("wParam=%d,lParam=%d", wParam, lParam);
	AfxMessageBox(str);
	return 0;
}

/*
* 应用程序类
*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance() override;//覆写父类的InitInstance函数
};

CMyWinApp theApp;//爆破点

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCCreate");
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}
