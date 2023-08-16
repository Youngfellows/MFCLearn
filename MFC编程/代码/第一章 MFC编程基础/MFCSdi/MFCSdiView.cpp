
// MFCSdiView.cpp : implementation of the CMFCSdiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCSdi.h"
#endif

#include "MFCSdiDoc.h"
#include "MFCSdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSdiView

IMPLEMENT_DYNCREATE(CMFCSdiView, CView)

BEGIN_MESSAGE_MAP(CMFCSdiView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCSdiView construction/destruction

CMFCSdiView::CMFCSdiView()
{
	// TODO: add construction code here

}

CMFCSdiView::~CMFCSdiView()
{
}

BOOL CMFCSdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCSdiView drawing

void CMFCSdiView::OnDraw(CDC* /*pDC*/)
{
	CMFCSdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCSdiView printing

BOOL CMFCSdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCSdiView diagnostics

#ifdef _DEBUG
void CMFCSdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSdiDoc* CMFCSdiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSdiDoc)));
	return (CMFCSdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSdiView message handlers
