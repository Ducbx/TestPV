
// TestViewRGBView.cpp : implementation of the CTestViewRGBView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestViewRGB.h"
#endif

#include "TestViewRGBDoc.h"
#include "TestViewRGBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestViewRGBView

IMPLEMENT_DYNCREATE(CTestViewRGBView, CView)

BEGIN_MESSAGE_MAP(CTestViewRGBView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestViewRGBView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestViewRGBView construction/destruction

CTestViewRGBView::CTestViewRGBView()
{
	// TODO: add construction code here
	m_Image = NULL;
}

CTestViewRGBView::~CTestViewRGBView()
{
}

BOOL CTestViewRGBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestViewRGBView drawing

void CTestViewRGBView::OnDraw(CDC* pDC)
{
	CTestViewRGBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rc;
	GetClientRect(&rc);
	m_Image->LoadFromResource(::GetModuleHandle(NULL), IDB_BITMAP_LAMBO);
	m_Image->Draw(pDC->m_hDC, rc.left, rc.top, m_Image->GetWidth(), m_Image->GetHeight(), 0, 0,
		m_Image->GetWidth(), m_Image->GetHeight());
}


// CTestViewRGBView printing


void CTestViewRGBView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestViewRGBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestViewRGBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestViewRGBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestViewRGBView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestViewRGBView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestViewRGBView diagnostics

#ifdef _DEBUG
void CTestViewRGBView::AssertValid() const
{
	CView::AssertValid();
}

void CTestViewRGBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestViewRGBDoc* CTestViewRGBView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestViewRGBDoc)));
	return (CTestViewRGBDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestViewRGBView message handlers
