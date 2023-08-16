
// MFCDlgWizardDlg.h : header file
//

#pragma once


// CMFCDlgWizardDlg dialog
class CMFCDlgWizardDlg : public CDialog
{
// Construction
public:
	CMFCDlgWizardDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDLGWIZARD_DIALOG };

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
	CButton m_btn;
	afx_msg void OnClickedButton1();
	CEdit m_edit;
	CString m_str;
	afx_msg void OnChangeEdit1();
};
