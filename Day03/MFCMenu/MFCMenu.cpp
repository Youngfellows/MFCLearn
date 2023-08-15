#include<afxwin.h>
#include"resource.h"

/*�����*/
class CMyFrameWnd : public CFrameWnd {
	DECLARE_MESSAGE_MAP()//��Ϣӳ����ƴ�����Ϣ

public:
	afx_msg int OnCreate(LPCREATESTRUCT pcs);
	afx_msg void OnNew();//����˵��ĵ���¼�
	afx_msg void OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i);//���ò˵���״̬
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint pt);//�Ҽ��˵�

public:
	CMenu menu;
};

//��Ϣӳ����ƴ�����Ϣ
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	//ON_COMMAND(ID_NEW, OnNew)
	ON_WM_INITMENUPOPUP()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()

//��ʽ2:���ز˵�
int CMyFrameWnd::OnCreate(LPCREATESTRUCT pcs)
{
	menu.LoadMenu(IDR_MENU1);
	//this->SetMenu(&menu);
	::SetMenu(this->m_hWnd, menu.m_hMenu);  
	return CFrameWnd::OnCreate(pcs);
}

//����˵��ĵ���¼�
void CMyFrameWnd::OnNew()
{
	AfxMessageBox("����ദ�����½��˵�����");
}

//���ò˵���״̬
void CMyFrameWnd::OnInitMenuPopup(CMenu* pPopup, UINT nPos, BOOL i)
{
	//pPopup->CheckMenuItem(ID_NEW, MF_CHECKED);
	::CheckMenuItem(pPopup->m_hMenu, ID_NEW, MF_CHECKED);
}

//�Ҽ��˵�
void CMyFrameWnd::OnContextMenu(CWnd* pWnd, CPoint pt)
{
	//CMenu* pPopup = menu.GetSubMenu(0);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, this);

	HMENU hPopup = ::GetSubMenu(menu.m_hMenu, 0);
	::TrackPopupMenu(hPopup, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, this->m_hWnd, NULL);
}

/*Ӧ�ó�����*/
class CMyWinApp : public CWinApp {
	DECLARE_MESSAGE_MAP()//��Ϣӳ����ƴ�����Ϣ

public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
};

//��Ϣӳ����ƴ�����Ϣ
BEGIN_MESSAGE_MAP(CMyWinApp, CWinApp)
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd();
	pFrame->Create(NULL, "MFCMenu");
	//��ʽ1:���ز˵�
	//pFrame->Create(NULL, "MFCMenu", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, (char*)IDR_MENU1);
	this->m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

//����˵��ĵ���¼�
void CMyWinApp::OnNew()
{
	AfxMessageBox("Ӧ�ó����ദ�����½��˵�����");
}

/*���Ƶ�*/
CMyWinApp theApp;