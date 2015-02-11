
// TradingAppController.h : main header file for the TradingAppController application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTradingAppControllerApp:
// See TradingAppController.cpp for the implementation of this class
//

class CTradingAppControllerApp : public CWinApp
{
public:
	CTradingAppControllerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTradingAppControllerApp theApp;
