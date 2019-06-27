
// ChartDucbx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CChartDucbxApp:
// See ChartDucbx.cpp for the implementation of this class
//

class CChartDucbxApp : public CWinApp
{
public:
	CChartDucbxApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
private:
	ULONG_PTR m_nGdiplusToken;

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CChartDucbxApp theApp;