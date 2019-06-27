
// ChartDucbxDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ChartContainer.h"
#include "ChartDef.h"

// CChartDucbxDlg dialog
class CChartDucbxDlg : public CDialogEx
{
// Construction
public:
	CChartDucbxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHARTDUCBX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btn_;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSize(UINT nType,int cx,int cy);
	//afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CChartContainer m_chartContainerUp;
	CChartContainer m_chartContainerDown;
	BOOL m_bIsDrawn;
	CRect m_OldWndRect;
};
