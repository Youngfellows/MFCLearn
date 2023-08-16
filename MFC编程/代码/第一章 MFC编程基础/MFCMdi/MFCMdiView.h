
// MFCMdiView.h : interface of the CMFCMdiView class
//

#pragma once


class CMFCMdiView : public CView
{
protected: // create from serialization only
	CMFCMdiView();
	DECLARE_DYNCREATE(CMFCMdiView)

// Attributes
public:
	CMFCMdiDoc* GetDocument() const;

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
	virtual ~CMFCMdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCMdiView.cpp
inline CMFCMdiDoc* CMFCMdiView::GetDocument() const
   { return reinterpret_cast<CMFCMdiDoc*>(m_pDocument); }
#endif

