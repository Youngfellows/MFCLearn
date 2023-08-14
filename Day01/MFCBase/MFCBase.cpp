#include<afxwin.h>

/*
 * 应用程序框架类
 */
class CMyFrameWnd : public CFrameWnd {

};

/*
 * 应用程序类
 */
class CMyWinApp : public CWinApp {
public:
	CMyWinApp() {
	}

	virtual BOOL InitInstance()
	{
		CMyFrameWnd* pFrame = new CMyFrameWnd();
		pFrame->Create(NULL, "MFCBase");
		m_pMainWnd = pFrame;
		pFrame->ShowWindow(SW_SHOW);
		pFrame->UpdateWindow();
		return TRUE;
	}
};

CMyWinApp theApp;//爆破点