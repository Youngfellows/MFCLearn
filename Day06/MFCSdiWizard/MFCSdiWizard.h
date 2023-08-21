
// MFCSdiWizard.h : main header file for the MFCSdiWizard application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSdiWizardApp:
// See MFCSdiWizard.cpp for the implementation of this class
//

class CMFCSdiWizardApp : public CWinApp
{
public:
	CMFCSdiWizardApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSdiWizardApp theApp;
