
// MFCCtrl3Dlg.h : header file
//

#pragma once


// CMFCCtrl3Dlg dialog
class CMFCCtrl3Dlg : public CDialogEx
{
// Construction
public:
	CMFCCtrl3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCCTRL3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_dropdown;
	CComboBox m_droplist;
	CComboBox m_simple;
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedText();
	afx_msg void OnBnClickedData();
	afx_msg void OnSelchangeSimple();
	afx_msg void OnEditchangeSimple();
};
