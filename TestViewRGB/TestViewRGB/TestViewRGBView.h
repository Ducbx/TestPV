
// TestViewRGBView.h : interface of the CTestViewRGBView class
//

#pragma once


class CTestViewRGBView : public CView
{
protected: // create from serialization only
	CTestViewRGBView();
	DECLARE_DYNCREATE(CTestViewRGBView)

// Attributes
public:
	CTestViewRGBDoc* GetDocument() const;

// Operations
public:
	CImage *m_Image;
	CBitmap bmp;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTestViewRGBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestViewRGBView.cpp
inline CTestViewRGBDoc* CTestViewRGBView::GetDocument() const
   { return reinterpret_cast<CTestViewRGBDoc*>(m_pDocument); }
#endif

