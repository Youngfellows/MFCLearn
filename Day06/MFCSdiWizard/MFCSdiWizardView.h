
// MFCSdiWizardView.h : interface of the CMFCSdiWizardView class
//

#pragma once


class CMFCSdiWizardView : public CView
{
protected: // create from serialization only
	CMFCSdiWizardView() noexcept;
	DECLARE_DYNCREATE(CMFCSdiWizardView)

// Attributes
public:
	CMFCSdiWizardDoc* GetDocument() const;

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
	virtual ~CMFCSdiWizardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTest();
};

#ifndef _DEBUG  // debug version in MFCSdiWizardView.cpp
inline CMFCSdiWizardDoc* CMFCSdiWizardView::GetDocument() const
   { return reinterpret_cast<CMFCSdiWizardDoc*>(m_pDocument); }
#endif

