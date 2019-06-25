// LeftDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplitWindow.h"
#include "LeftDlg.h"


// CLeftDlg

IMPLEMENT_DYNCREATE(CLeftDlg, CFormView)

CLeftDlg::CLeftDlg()
	: CFormView(IDD_LEFT_DLG)
{

}

CLeftDlg::~CLeftDlg()
{
}

void CLeftDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_HELLO, m_btnHello);
}

BEGIN_MESSAGE_MAP(CLeftDlg, CFormView)
END_MESSAGE_MAP()


// CLeftDlg diagnostics

#ifdef _DEBUG
void CLeftDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftDlg message handlers
void CLeftDlg::SetTaget(CWnd* taget)
{
	m_pTaget = taget;
}

BOOL CLeftDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if (m_pTaget)
	{
		m_pTaget->SendMessage(WM_COMMAND, wParam, lParam);
	}
	else
	{
		CFormView::OnCommand(wParam, lParam);
	}
	return true;
}


