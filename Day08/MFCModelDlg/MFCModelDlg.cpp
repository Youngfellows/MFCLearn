#include <afxwin.h>
#include "resource.h"

/*
* �Ի�����
*/
class CMyDlg :public CDialog {
	DECLARE_MESSAGE_MAP()//��Ϣӳ�����

public:
	enum { IDD = IDD_DIALOG1 };

public:
	CMyDlg() : CDialog(IDD) {
	}
	afx_msg void OnOK();
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_COMMAND(IDOK, OnOK)
END_MESSAGE_MAP()

void CMyDlg::OnOK()
{
	CDialog::OnOK();
}


/*
* Ӧ�ó�����
*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	//MFCģʽ�Ի���(�ٵ�)
	CMyDlg dlg;//ջ�ռ�
	this->m_pMainWnd = &dlg;
	int nRet = dlg.DoModal();
	return FALSE;//����ִ��MFC���а��ŵ�Run����
}

CMyWinApp theApp;//���Ƶ�