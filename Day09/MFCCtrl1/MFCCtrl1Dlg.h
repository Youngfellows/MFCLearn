
// MFCCtrl1Dlg.h: 头文件
//

#pragma once


// CMFCCtrl1Dlg 对话框
class CMFCCtrl1Dlg : public CDialogEx
{
// 构造
public:
	CMFCCtrl1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCTRL1_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_vlistbox;
	CListBox m_hlistbox;
	CStatic m_st1;
	CStatic m_st2;
	afx_msg void OnClickedClear();
	afx_msg void OnClickedDel();
	afx_msg void OnClickedText();
	afx_msg void OnClickedData();
	afx_msg void OnSelchangeVlist();
};
