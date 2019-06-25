#pragma once
#include "afxwin.h"



// CLeftDlg form view

class CLeftDlg : public CFormView
{
	DECLARE_DYNCREATE(CLeftDlg)

protected:
	CLeftDlg();           // protected constructor used by dynamic creation
	virtual ~CLeftDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LEFT_DLG };
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
	CButton m_btnHello;
	CWnd* m_pTaget;
public:
	void SetTaget(CWnd* taget);
protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};


