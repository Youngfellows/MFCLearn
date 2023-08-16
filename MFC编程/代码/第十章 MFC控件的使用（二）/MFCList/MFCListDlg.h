
// MFCListDlg.h : header file
//

#pragma once


// CMFCListDlg dialog
class CMFCListDlg : public CDialogEx
{
// Construction
public:
	CMFCListDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCLIST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combox;
	CListCtrl m_list;
	afx_msg void OnSelchangeCombo1();
	void ShowFile( CString path );
	afx_msg void OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
