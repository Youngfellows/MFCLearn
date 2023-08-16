
// MFCMdi.h : main header file for the MFCMdi application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMdiApp:
// See MFCMdi.cpp for the implementation of this class
//

class CMFCMdiApp : public CWinApp
{
public:
	CMFCMdiApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMdiApp theApp;
