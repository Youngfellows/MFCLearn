
// MFCSdiWizard.h : main header file for the MFCSdiWizard application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSdiWizardApp:
// See MFCSdiWizard.cpp for the implementation of this class
//

class CMFCSdiWizardApp : public CWinApp
{
public:
	CMFCSdiWizardApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSdiWizardApp theApp;
