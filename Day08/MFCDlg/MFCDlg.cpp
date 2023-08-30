#include<afxwin.h>
#include "resource.h"

class CMyDlg : public CDialog {
	DECLARE_MESSAGE_MAP()//消息映射机制

public:
	afx_msg void OnZjwOK();
	afx_msg void OnZjwCancel();
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_COMMAND(IDOK, OnZjwOK)
	ON_COMMAND(IDCANCEL, OnZjwCancel)
END_MESSAGE_MAP()

void CMyDlg::OnZjwOK()
{
	//CDialog::OnOK();//只能将无模式对话框隐藏，并没有销毁。
	::DestroyWindow(this->m_hWnd);//销毁对话框
}

void CMyDlg::OnZjwCancel()
{
	//CDialog::OnCancel();
	DestroyWindow();//销毁对话框
}


/*
* 应用程序类
*/
class CMyWinApp : public CWinApp {
public:
	CMyWinApp() : CWinApp() {

	}
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance() {
	//MFC无模式对话框
	CMyDlg* pdlg = new CMyDlg();
	pdlg->Create(IDD_DIALOG1);
	this->m_pMainWnd = pdlg;
	pdlg->ShowWindow(SW_SHOW);
	return TRUE;
}

CMyWinApp theApp;