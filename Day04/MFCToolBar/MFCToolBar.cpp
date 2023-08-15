#include<afxwin.h>
#include<afxext.h>
#include "resource.h"

/*�����*/
class CMyFrameWnd :public CFrameWnd {
	DECLARE_MESSAGE_MAP()//��Ϣӳ�����
public:
	afx_msg void OnNew();
	afx_msg void OnSave();
	afx_msg void OnSet();
	afx_msg int OnCreate(LPCREATESTRUCT pcs);

public:
	CToolBar toolbar;
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_COMMAND(ID_NEW, OnNew)
	ON_COMMAND(ID_SAVE, OnSave)
	ON_COMMAND(ID_SET, OnSet)
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("�½��˵�����");
}

void CMyFrameWnd::OnSet()
{
	AfxMessageBox("��ɫ���߰�ť�������");
}

void CMyFrameWnd::OnSave()
{
	AfxMessageBox("��ɫ���߰�ť�������");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	//���ع�����
	toolbar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER);
	toolbar.LoadToolBar(IDR_TOOLBAR1);
	toolbar.EnableDocking(CBRS_ALIGN_ANY);
	this->EnableDocking(CBRS_ALIGN_ANY);
	this->DockControlBar(&toolbar, AFX_IDW_DOCKBAR_BOTTOM);
	return CFrameWnd::OnCreate(pcs);
}

/*Ӧ�ó�����*/
class CMyWinApp :public CWinApp {

public:
	virtual BOOL InitInstance() override;
};

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	//pFrame->Create(NULL, "MFCToolBar");
	//���ز˵���
	pFrame->Create(NULL, "MFCToolBar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, (CHAR*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

CMyWinApp theApp;//���Ƶ�