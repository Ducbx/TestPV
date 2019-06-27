
// ChartDucbxDlg.cpp : implementation file
//

#include "stdafx.h"
#include <iostream>
#include "ChartDucbx.h"
#include "ChartDucbxDlg.h"
#include "afxdialogex.h"
#include "opencv2\opencv.hpp"

using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChartDucbxDlg dialog



CChartDucbxDlg::CChartDucbxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHARTDUCBX_DIALOG, pParent),
	m_bIsDrawn(FALSE),
	m_OldWndRect(0,0,0,0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChartDucbxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_);
	DDX_Control(pDX, IDC_CONTAINER_UP, m_chartContainerUp);
	DDX_Control(pDX, IDC_CONTAINER_DOWN, m_chartContainerDown);
}

BEGIN_MESSAGE_MAP(CChartDucbxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_SIZE()
	//ON_WM_LBUTTONUP()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChartDucbxDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChartDucbxDlg message handlers

BOOL CChartDucbxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_chartContainerUp.SetContainerName(string_t(_T("Demo chart container Upside")));
	m_chartContainerDown.SetContainerName(string_t(_T("Demo chart container DownSide")));

	GetClientRect(&m_OldWndRect);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChartDucbxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChartDucbxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChartDucbxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//in ChartDucbxApp - initInstance need add
//GdiplusStartupInput gdiplusStartupInput;
//GdiplusStartup(&m_nGdiplusToken, &gdiplusStartupInput, NULL);
void CChartDucbxDlg::OnBnClickedButton1()
{
	if (m_bIsDrawn)
	{
		return;
	}
	Mat src, dst;
	src = imread("ducbx.jpg", CV_LOAD_IMAGE_COLOR);
	if (!src.data)
	{
		return;
	}
	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;

	Mat b_hist, g_hist, r_hist;

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	//Draw chart
	COLORREF colorR, colorG, colorB;
	colorR = RGB(255, 0, 0); // red
	colorG = RGB(0, 255, 0); // red
	colorB = RGB(0, 0, 255); // red
	Gdiplus::Color colChartR = Color(255, GetRValue(colorR), GetGValue(colorR), GetBValue(colorR));
	Gdiplus::Color colChartG = Color(255, GetRValue(colorG), GetGValue(colorG), GetBValue(colorG));
	Gdiplus::Color colChartB = Color(255, GetRValue(colorB), GetGValue(colorB), GetBValue(colorB));

	V_CHARTDATAD vDataR, vDataG, vDataB;
	vDataR.resize(histSize, PointD(0.0, 0.0));
	vDataG.resize(histSize, PointD(0.0, 0.0));
	vDataB.resize(histSize, PointD(0.0, 0.0));
	for (int i = 0; i < histSize; i++)
	{
		double pntX = (i);

		double pntYR = cvRound(r_hist.at<float>(i));
		vDataR[i] = PointD(pntX, pntYR);

		double pntYG = cvRound(g_hist.at<float>(i));
		vDataG[i] = PointD(pntX, pntYG);

		double pntYB = cvRound(b_hist.at<float>(i));
		vDataB[i] = PointD(pntX, pntYB);
	}

	_TCHAR buffer_t[64];
	_itot_s(m_chartContainerUp.GetMaxChartIdx() + 1, buffer_t, 10);  // Chart idx to string
	string_t idxStr(buffer_t);


	int chartIdxR = m_chartContainerUp.AddChart(
		true,
		true,
		L"aimesoft_R",
		L"test",
		3,
		Gdiplus::DashStyle::DashStyleSolid,
		2.0,
		0.0,
		colChartR,
		vDataR,
		true);

	int chartIdxG = m_chartContainerUp.AddChart(
		true,
		true,
		L"aimesoft_G",
		L"test",
		3,
		Gdiplus::DashStyle::DashStyleSolid,
		2.0,
		0.0,
		colChartG,
		vDataG,
		true);

	int chartIdxB = m_chartContainerDown.AddChart(
		true,
		true,
		L"aimesoft_B",
		L"test",
		3,
		Gdiplus::DashStyle::DashStyleSolid,
		2.0,
		0.0,
		colChartB,
		vDataB,
		true);

	m_chartContainerUp.ShowNamesLegend();
	m_chartContainerDown.ShowNamesLegend();

	if (chartIdxR == -1)
	{
		MessageBox(L"Fail to add chart");
	}
	else
	{
		UpdateData(FALSE);
		m_chartContainerUp.SetFocus();
		m_chartContainerDown.SetFocus();
	}
	m_bIsDrawn = TRUE;
}

void CChartDucbxDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialogEx::OnSize(nType, cx, cy);

	if (!m_chartContainerUp.GetSafeHwnd() || !m_chartContainerDown.GetSafeHwnd())
	{
		return;
	}

	CRect currentWndRect;
	GetClientRect(&currentWndRect);

	CRect chartRect;
	m_chartContainerUp.GetClientRect(&chartRect);

	if (m_OldWndRect == currentWndRect)
	{
		return;
	}

	int iDeltaWidth = currentWndRect.Width() - m_OldWndRect.Width();
	int iNewWidth = chartRect.Width() + iDeltaWidth / 2;

	m_chartContainerUp.MoveWindow(0, 0, iNewWidth, currentWndRect.Height()-40);
	m_chartContainerDown.MoveWindow(currentWndRect.Width()/2, 0, iNewWidth, currentWndRect.Height()-40);


	m_chartContainerUp.UpdateContainerWnds();
	m_chartContainerDown.UpdateContainerWnds();
	//m_chartContainerUp.RefreshWnd();
	//m_chartContainerDown.RefreshWnd();
	//m_chartContainerUp.ShowNamesLegend();
	//m_chartContainerDown.ShowNamesLegend();
	m_OldWndRect = currentWndRect;
}

//void CChartDucbxDlg::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	if (!m_chartContainerUp.GetSafeHwnd() || !m_chartContainerDown.GetSafeHwnd())
//	{
//		return;
//	}
//
//	CRect currentWndRect;
//	GetClientRect(&currentWndRect);
//
//	if (m_OldWndRect != currentWndRect)
//	{
//		CRect chartRect;
//		m_chartContainerUp.GetClientRect(&chartRect);
//
//		int iDeltaWidth = currentWndRect.Width() - m_OldWndRect.Width();
//		int iNewWidth = chartRect.Width() + iDeltaWidth / 2;
//
//		m_chartContainerUp.MoveWindow(0, 0, iNewWidth, currentWndRect.Height() - 40);
//		m_chartContainerDown.MoveWindow(currentWndRect.Width() / 2, 0, iNewWidth, currentWndRect.Height() - 40);
//
//
//		m_chartContainerUp.UpdateContainerWnds();
//		m_chartContainerDown.UpdateContainerWnds();
//
//		m_OldWndRect = currentWndRect;
//	}
//
//	
//	//m_chartContainerUp.RefreshWnd();
//	//m_chartContainerDown.RefreshWnd();
//	//m_chartContainerUp.ShowNamesLegend();
//	//m_chartContainerDown.ShowNamesLegend();
//}