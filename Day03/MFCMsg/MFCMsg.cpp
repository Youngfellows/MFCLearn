#include<afxwin.h>

/*
* 应用程序框架类
*/
class CMyFrameWnd : public CFrameWnd {
	//DECLARE_MESSAGE_MAP()

//替换宏
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap();
	virtual const AFX_MSGMAP* GetMessageMap() const override;
public:
	LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
};

//BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
//	ON_MESSAGE(WM_CREATE, OnCreate)
//END_MESSAGE_MAP()

//把上面的宏给替换为下面的函数
//PTM_WARNING_DISABLE
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const
{
	return GetThisMessageMap();
}

const AFX_MSGMAP* PASCAL CMyFrameWnd::GetThisMessageMap()
{
	typedef CMyFrameWnd ThisClass;
	typedef CFrameWnd TheBaseClass;
	//__pragma(warning(push))
	//	__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
	static const AFX_MSGMAP_ENTRY _messageEntries[] =
	{
		/////
		{ WM_CREATE, 0, 0, 0, AfxSig_lwl,(AFX_PMSG)(AFX_PMSGW)(static_cast<LRESULT(AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM)> (&OnCreate)) },
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
	};
	//__pragma(warning(pop))
	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
	return &messageMap;
}
//PTM_WARNING_RESTORE

LRESULT CMyFrameWnd::OnCreate(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox("WM_CREATE消息被处理了");
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
