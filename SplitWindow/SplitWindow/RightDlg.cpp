// RightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplitWindow.h"
#include "RightDlg.h"


// CRightDlg

IMPLEMENT_DYNCREATE(CRightDlg, CFormView)

CRightDlg::CRightDlg()
	: CFormView(IDD_RIGHT_DLG)
{

}

CRightDlg::~CRightDlg()
{
}

void CRightDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STT_HELLO, m_sttHello);
}

BEGIN_MESSAGE_MAP(CRightDlg, CFormView)
	ON_BN_CLICKED(IDC_BTN_HELLO, OnBnClickedBtnHello)
END_MESSAGE_MAP()


// CRightDlg diagnostics

#ifdef _DEBUG
void CRightDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRightDlg message handlers
void CRightDlg::OnBnClickedBtnHello()
{
	// TODO: Add your control notification handler code here
	m_sttHello.SetWindowText(L"Hello Window Splitter!");

}