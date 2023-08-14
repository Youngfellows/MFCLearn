#include<afxwin.h>

/*
* Ӧ�ó�������
*/
class CMyFrameWnd : public CFrameWnd {

public:
	/*
	* ���ڴ�����
	*/
	virtual LRESULT WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam);
};


LRESULT CMyFrameWnd::WindowProc(UINT msgID, WPARAM wParam, LPARAM lParam) {
	//�˺����ڲ���thisΪpFrame
	switch (msgID)
	{
	case WM_CREATE:
		AfxMessageBox("WM_CREATE��Ϣ������");
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
* Ӧ�ó�����
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

CMyWinApp theApp;//���Ƶ�