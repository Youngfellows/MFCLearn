
// MFCDrawView.h : interface of the CMFCDrawView class
//

#pragma once


class CMFCDrawView : public CView
{
protected: // create from serialization only
	CMFCDrawView();
	DECLARE_DYNCREATE(CMFCDrawView)

// Attributes
public:
	CMFCDrawDoc* GetDocument() const;

// Operations
public:

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
	virtual ~CMFCDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnClient();
	afx_msg void OnPen();
	afx_msg void OnBrush();
	afx_msg void OnFont();
	afx_msg void OnBmp();
};

#ifndef _DEBUG  // debug version in MFCDrawView.cpp
inline CMFCDrawDoc* CMFCDrawView::GetDocument() const
   { return reinterpret_cast<CMFCDrawDoc*>(m_pDocument); }
#endif

