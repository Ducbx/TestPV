#pragma once
#include "afxwin.h"



// CRightDlg form view

class CRightDlg : public CFormView
{
	DECLARE_DYNCREATE(CRightDlg)

protected:
	CRightDlg();           // protected constructor used by dynamic creation
	virtual ~CRightDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RIGHT_DLG };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CStatic m_sttHello;
public:
	afx_msg void OnBnClickedBtnHello();
};


