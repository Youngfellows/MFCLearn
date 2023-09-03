
// MFCCtrl3Dlg.h: 头文件
//

#pragma once


// CMFCCtrl3Dlg 对话框
class CMFCCtrl3Dlg : public CDialogEx
{
// 构造
public:
	CMFCCtrl3Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCTRL3_DIALOG };
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
	afx_msg void OnClickedClear();
	afx_msg void OnClickedDel();
	afx_msg void OnClickedText();
	afx_msg void OnClickedData();
	CComboBox m_simple;
	CComboBox m_droplist;
	CComboBox m_dropdown;
	afx_msg void OnSelchangeSimple();
	afx_msg void OnEditchangeSimple();
};
