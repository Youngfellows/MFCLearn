#include<afxwin.h>

/*
* Ӧ�ó�������
*/
class CMyFrameWnd : public CFrameWnd {
	//DECLARE_MESSAGE_MAP()

//�滻��
protected:
	static const AFX_MSGMAP* PASCAL GetThisMessageMap();
	virtual const AFX_MSGMAP* GetMessageMap() const override;
public:
	LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
};

//BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
//	ON_MESSAGE(WM_CREATE, OnCreate)
//END_MESSAGE_MAP()

//������ĺ���滻Ϊ����ĺ���
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
	AfxMessageBox("WM_CREATE��Ϣ��������");
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
