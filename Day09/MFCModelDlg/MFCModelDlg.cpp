#include <afxwin.h>
#include "resource.h"

/*
* �Ի�����
*/
class CMyDlg :public CDialog {
	DECLARE_MESSAGE_MAP()//��Ϣӳ�����

public:
	enum { IDD = IDD_DIALOG1 };
	CString m_strEdit;//�������Ͷ���
	CEdit m_ctrlEdit;//�ؼ����Ͷ���

public:
	CMyDlg() : CDialog(IDD) {
	}
	afx_msg void OnOK();
	afx_msg void OnBtn1();
	afx_msg void OnBtn2();
	afx_msg void OnDblClk();
	virtual void DoDataExchange(CDataExchange* pDX);
};
BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	/*ON_COMMAND(IDOK, OnOK)
	ON_COMMAND(IDC_BUTTON1, OnBtn1)
	ON_COMMAND(IDC_BUTTON2, OnBtn2)*/
	ON_BN_CLICKED(IDOK, OnOK)
	ON_BN_CLICKED(IDC_BUTTON1, OnBtn1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBtn2)
	/*	{ WM_COMMAND, (WORD)BN_CLICKED, (WORD)IDC_BUTTON2, (WORD)IDC_BUTTON2, AfxSigCmd_v,
		(static_cast< AFX_PMSG > (OnBtn1)) },*/
	ON_BN_DOUBLECLICKED(IDC_BUTTON2, OnDblClk)
	/*	{ WM_COMMAND, (WORD)BN_DOUBLECLICKED, (WORD)IDC_BUTTON2, (WORD)IDC_BUTTON2, AfxSigCmd_v,
			(static_cast< AFX_PMSG > (OnDblClk)) },*/
END_MESSAGE_MAP()

void CMyDlg::OnOK()
{
	//CDialog::OnOK();
	m_ctrlEdit.MoveWindow(0, 0, 200, 100);
}

/*
* �ؼ�--�����ݶ���
*/
void CMyDlg::OnBtn1()
{
	UpdateData(TRUE);
	AfxMessageBox(m_strEdit);
}

/*
* ���ݶ���--���ؼ�
*/
void CMyDlg::OnBtn2()
{
	m_strEdit = "Hello Visual Studio";
	UpdateData(FALSE);
}

void CMyDlg::OnDblClk()
{
	AfxMessageBox("˫���˰�ť");
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT1, m_strEdit);//����һϵ��DDX_xxx�����������Զ���ӣ�
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
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

