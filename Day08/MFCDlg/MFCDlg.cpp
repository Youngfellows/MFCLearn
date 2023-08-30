#include<afxwin.h>
#include "resource.h"

class CMyDlg : public CDialog {
	DECLARE_MESSAGE_MAP()//��Ϣӳ�����

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
	//CDialog::OnOK();//ֻ�ܽ���ģʽ�Ի������أ���û�����١�
	::DestroyWindow(this->m_hWnd);//���ٶԻ���
}

void CMyDlg::OnZjwCancel()
{
	//CDialog::OnCancel();
	DestroyWindow();//���ٶԻ���
}


/*
* Ӧ�ó�����
*/
class CMyWinApp : public CWinApp {
public:
	CMyWinApp() : CWinApp() {

	}
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance() {
	//MFC��ģʽ�Ի���
	CMyDlg* pdlg = new CMyDlg();
	pdlg->Create(IDD_DIALOG1);
	this->m_pMainWnd = pdlg;
	pdlg->ShowWindow(SW_SHOW);
	return TRUE;
}

CMyWinApp theApp;