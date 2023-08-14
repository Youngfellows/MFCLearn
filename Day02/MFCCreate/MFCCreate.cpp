#include<afxwin.h>

/*
* 应用程序框架类
*/
class CMyFrameWnd : public CFrameWnd {

public:
	/*
	* 窗口处理函数
	*/
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam);
};


LRESULT CMyFrameWnd::WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam) {
	//此函数内部的this为pFrame
	switch (msgID)
	{
	case WM_CREATE:
		AfxMessageBox("WM_CREATE消息被处理");
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps = { 0 };
		HDC hdc = ::BeginPaint(this->m_hWnd, &ps);
		const char* pszText = "hello world";
		::TextOut(hdc, 100, 100, pszText, strlen(pszText));
		::EndPaint(this->m_hWnd, &ps);
	}
	break;
	default:
		break;
	}
	return CFrameWnd::WindowProc(msgID, wParam, lParam);
}

/*
* 应用程序类
*/
class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance();

};

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//爆破点