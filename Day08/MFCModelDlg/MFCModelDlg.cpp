#include <afxwin.h>
#include "resource.h"

/*
* 对话框类
*/
class CMyDlg :public CDialog {
	DECLARE_MESSAGE_MAP()//消息映射机制

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
* 应用程序类
*/
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyWinApp::InitInstance()
{
	//MFC模式对话框(假的)
	CMyDlg dlg;//栈空间
	this->m_pMainWnd = &dlg;
	int nRet = dlg.DoModal();
	return FALSE;//不再执行MFC库中安排的Run函数
}

CMyWinApp theApp;//爆破点