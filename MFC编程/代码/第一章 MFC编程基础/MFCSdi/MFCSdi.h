
// MFCSdi.h : main header file for the MFCSdi application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSdiApp:
// See MFCSdi.cpp for the implementation of this class
//

class CMFCSdiApp : public CWinApp
{
public:
	CMFCSdiApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSdiApp theApp;
