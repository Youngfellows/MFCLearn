// MFCDll.h : main header file for the MFCDll DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCDllApp
// See MFCDll.cpp for the implementation of this class
//

class CMFCDllApp : public CWinApp
{
public:
	CMFCDllApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
