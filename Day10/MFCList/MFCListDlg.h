
// MFCListDlg.h: 头文件
//

#pragma once


// CMFCListDlg 对话框
class CMFCListDlg : public CDialogEx
{
	// 构造
public:
	CMFCListDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCLIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void TestData();
	void ShowFile(CString path);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CComboBox m_combox;
	afx_msg void OnSelchangeCombo();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
};
