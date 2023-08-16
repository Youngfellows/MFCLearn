
// MFCSdiView.h : interface of the CMFCSdiView class
//

#pragma once


class CMFCSdiView : public CView
{
protected: // create from serialization only
	CMFCSdiView();
	DECLARE_DYNCREATE(CMFCSdiView)

// Attributes
public:
	CMFCSdiDoc* GetDocument() const;

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
	virtual ~CMFCSdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCSdiView.cpp
inline CMFCSdiDoc* CMFCSdiView::GetDocument() const
   { return reinterpret_cast<CMFCSdiDoc*>(m_pDocument); }
#endif

