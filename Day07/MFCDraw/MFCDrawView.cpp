
// MFCDrawView.cpp: CMFCDrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()//处理绘图消息
	ON_COMMAND(ID_CLIENT, &CMFCDrawView::OnClient)
	ON_COMMAND(ID_PEN, &CMFCDrawView::OnPen)
	ON_COMMAND(ID_BRUSH, &CMFCDrawView::OnBrush)
	ON_COMMAND(ID_BMP, &CMFCDrawView::OnBmp)
	ON_COMMAND(ID_FONT, &CMFCDrawView::OnFont)
END_MESSAGE_MAP()

// CMFCDrawView 构造/析构

CMFCDrawView::CMFCDrawView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView 绘图

void CMFCDrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDrawView 打印

BOOL CMFCDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDrawView 诊断

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView 消息处理程序


void CMFCDrawView::OnPaint()
{
	CPaintDC dc(this);//::BeginPaint
	dc.Rectangle(50, 50, 100, 100);//::Rectangle(...)
	//::Rectangle(dc.m_hDC, 50, 50, 100, 100);
}


void CMFCDrawView::OnClient()
{
	CClientDC dc(this);
	dc.Ellipse(120, 50, 170, 100);
}


void CMFCDrawView::OnPen()
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0));
	//CPen* oldpen = dc.SelectObject(&pen);
	HGDIOBJ nOldPen = ::SelectObject(dc.m_hDC, pen.m_hObject);

	//dc.Rectangle(50, 110, 100, 160);
	::Rectangle(dc.m_hDC, 50, 110, 100, 160);

	//dc.SelectObject(oldpen);
	::SelectObject(dc.m_hDC, nOldPen);

	//pen.DeleteObject();
	::DeleteObject(pen.m_hObject);
}


void CMFCDrawView::OnBrush()
{
	CClientDC dc(this);
	CBrush brush(RGB(0, 255, 0));
	CBrush* oldbrush = dc.SelectObject(&brush);
	dc.Rectangle(120, 110, 170, 160);
	dc.SelectObject(oldbrush);
	brush.DeleteObject();
}


void CMFCDrawView::OnBmp()
{
	//添加位图资源(操作资源无需写代码)

	//创建一个和当前DC,相匹配的内存DC
	CClientDC dc(this);
	CDC memdc;
	memdc.CreateCompatibleDC(&dc);//::CreateCompatibleDC

	//将位图的数据送给内存DC
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);//::LoadBitmap
	CBitmap* oldbmp = memdc.SelectObject(&bmp);//::SelectObject

	//成像
	dc.BitBlt(190, 50, 240, 100, &memdc, 0, 0, SRCCOPY);//::BitBlt

	//将位图数据要回来
	memdc.SelectObject(oldbmp);//::SelectObject

	//销毁位图
	bmp.DeleteObject();//::DeleteObject

	//销毁内存DC
	memdc.DeleteDC();//::DeleteDC

}


void CMFCDrawView::OnFont()
{
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, "黑体");//::CreateFont(..............)
	CFont* oldfont = dc.SelectObject(&font);
	dc.TextOut(50, 180, "Hello Visul Studio 2019.8.22");
	dc.SelectObject(oldfont);
	font.DeleteObject();
}
