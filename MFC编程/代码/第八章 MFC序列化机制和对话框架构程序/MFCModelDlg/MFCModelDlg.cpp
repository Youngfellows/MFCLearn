#include <afxwin.h>
#include "resource.h"
class CMyDlg : public CDialog{
public:
	DECLARE_MESSAGE_MAP( )
	enum{IDD=IDD_DIALOG1};
public:
	afx_msg void OnOK();
	CMyDlg() : CDialog(IDD){
	}
};
BEGIN_MESSAGE_MAP( CMyDlg, CDialog )
	ON_COMMAND( IDOK, OnOK )
END_MESSAGE_MAP( )
void CMyDlg::OnOK( ){
	CDialog::OnOK();
}
class CMyWinApp : public CWinApp{
public:
	virtual BOOL InitInstance( );
};
BOOL CMyWinApp::InitInstance( ){
	CMyDlg dlg;//栈空间
	m_pMainWnd = &dlg;
	int nRet = dlg.DoModal( );
	return FALSE;//不再执行MFC库中安排的Run函数
}
CMyWinApp theApp;