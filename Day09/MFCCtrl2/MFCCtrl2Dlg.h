
// MFCCtrl2Dlg.h : header file
//

#pragma once


// CMFCCtrl2Dlg dialog
class CMFCCtrl2Dlg : public CDialogEx
{
// Construction
public:
	CMFCCtrl2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCCTRL2_DIALOG };

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
	CButton m_check;
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedCheck1();
	CButton m_btn;
	CButton m_r1;
	CButton m_r2;
	afx_msg void OnClickedRadio1();
	afx_msg void OnClickedRadio2();
	CButton m_group;
	CStatic m_st;
	CStatic m_ps;
	CStatic m_ps2;
};
