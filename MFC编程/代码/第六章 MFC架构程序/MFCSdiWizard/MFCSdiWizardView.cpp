
// MFCSdiWizardView.cpp : implementation of the CMFCSdiWizardView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSdiWizard.h"
#endif

#include "MFCSdiWizardDoc.h"
#include "MFCSdiWizardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSdiWizardView

IMPLEMENT_DYNCREATE(CMFCSdiWizardView, CView)

BEGIN_MESSAGE_MAP(CMFCSdiWizardView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_TEST_TT, &CMFCSdiWizardView::OnTest)
END_MESSAGE_MAP()

// CMFCSdiWizardView construction/destruction

CMFCSdiWizardView::CMFCSdiWizardView()
{
	// TODO: add construction code here

}

CMFCSdiWizardView::~CMFCSdiWizardView()
{
}

BOOL CMFCSdiWizardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

// CMFCSdiWizardView drawing

void CMFCSdiWizardView::OnDraw(CDC* /*pDC*/)
{
	CMFCSdiWizardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCSdiWizardView printing

BOOL CMFCSdiWizardView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSdiWizardView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSdiWizardView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCSdiWizardView diagnostics

#ifdef _DEBUG
void CMFCSdiWizardView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSdiWizardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSdiWizardDoc* CMFCSdiWizardView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSdiWizardDoc)));
	return (CMFCSdiWizardDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSdiWizardView message handlers


void CMFCSdiWizardView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
}


void CMFCSdiWizardView::OnTest()
{
	// TODO: Add your command handler code here
	AfxMessageBox("点了菜单项");
}
