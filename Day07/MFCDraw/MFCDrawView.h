﻿
// MFCDrawView.h: CMFCDrawView 类的接口
//

#pragma once


class CMFCDrawView : public CView
{
protected: // 仅从序列化创建
	CMFCDrawView() noexcept;
	DECLARE_DYNCREATE(CMFCDrawView)

// 特性
public:
	CMFCDrawDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnClient();
	afx_msg void OnPen();
	afx_msg void OnBrush();
	afx_msg void OnBmp();
	afx_msg void OnFont();
};

#ifndef _DEBUG  // MFCDrawView.cpp 中的调试版本
inline CMFCDrawDoc* CMFCDrawView::GetDocument() const
   { return reinterpret_cast<CMFCDrawDoc*>(m_pDocument); }
#endif

