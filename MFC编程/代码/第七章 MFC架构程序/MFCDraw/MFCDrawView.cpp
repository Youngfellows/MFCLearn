
// MFCDrawView.cpp : implementation of the CMFCDrawView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCDraw.h"
#endif

#include "MFCDrawDoc.h"
#include "MFCDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawView

IMPLEMENT_DYNCREATE(CMFCDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_COMMAND(ID_CLIENT, &CMFCDrawView::OnClient)
	ON_COMMAND(ID_PEN, &CMFCDrawView::OnPen)
	ON_COMMAND(ID_BRUSH, &CMFCDrawView::OnBrush)
	ON_COMMAND(ID_FONT, &CMFCDrawView::OnFont)
	ON_COMMAND(ID_BMP, &CMFCDrawView::OnBmp)
END_MESSAGE_MAP()

// CMFCDrawView construction/destruction

CMFCDrawView::CMFCDrawView()
{
	// TODO: add construction code here

}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView drawing

void CMFCDrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCDrawView printing

BOOL CMFCDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCDrawView diagnostics

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView message handlers


void CMFCDrawView::OnPaint()
{
	CPaintDC dc(this); //::BeginPaint
//	dc.Rectangle( 100, 100, 300, 300 );//::Rectangle(...)
//	::Rectangle( dc.m_hDC, 100, 100, 300, 300 );
}

void CMFCDrawView::OnClient()
{
	CClientDC dc(this);
	dc.Ellipse( 300, 300, 500, 500 );
}


void CMFCDrawView::OnPen()
{
	CClientDC dc( this );
	CPen pen(PS_SOLID, 2, RGB(255,0,0));

//	CPen* oldpen = dc.SelectObject( &pen );
	HGDIOBJ nOldPen = ::SelectObject( dc.m_hDC, pen.m_hObject );

//	dc.Rectangle( 100, 100, 300, 300 );
	::Rectangle( dc.m_hDC, 100, 100, 300, 300 );

//	dc.SelectObject( oldpen );
	::SelectObject( dc.m_hDC, nOldPen );

//	pen.DeleteObject( );
	::DeleteObject( pen.m_hObject );
}


void CMFCDrawView::OnBrush()
{
	CClientDC dc(this);
	CBrush brush(RGB(0,255,0));
	CBrush* oldbrush = dc.SelectObject( &brush );
	dc.Rectangle( 100, 100, 300, 300 );
	dc.SelectObject( oldbrush );
	brush.DeleteObject( );
}


void CMFCDrawView::OnFont()
{
	CClientDC dc( this );
	CFont font;
	font.CreatePointFont(300, "黑体");//::CreateFont(..............)
	CFont* oldfont = dc.SelectObject( &font );
	dc.TextOut( 100, 100, "hello");
	dc.SelectObject( oldfont );
	font.DeleteObject();
}


void CMFCDrawView::OnBmp()
{
	//添加位图资源(操作资源无需写代码)

	//创建一个和当前DC,相匹配的内存DC
	CClientDC dc( this );
	CDC memdc;
	memdc.CreateCompatibleDC( &dc ); //::CreateCompatibleDC
	//将位图的数据送给内存DC
	CBitmap bmp;
	bmp.LoadBitmap( IDB_BITMAP1 ); //::LoadBitmap


	CBitmap* oldbmp = memdc.SelectObject( &bmp );//::SelectObject
	//成像
	dc.BitBlt( 100, 100, 48, 48, &memdc, 0, 0, SRCCOPY );//::BitBlt
	//将位图数据要回来
	memdc.SelectObject( oldbmp );//::SelectObject
	//销毁位图
	bmp.DeleteObject( );//::DeleteObject
	//销毁内存DC
	memdc.DeleteDC( );//::DeleteDC
}
