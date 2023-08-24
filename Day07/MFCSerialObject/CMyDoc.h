#pragma once
#include<afxwin.h>

/*
* 可以被序列化的类
*/
class CMyDoc : public CDocument {
	_DECLARE_DYNCREATE(CMyDoc);//动态创建机制的声明宏
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc*& pOb);//操作符重载函数

public:
	int m_age;
	float m_score;
	CString m_name;

public:
	CMyDoc(int age = 0, float score = 0.0, CString name = "");
	virtual void Serialize(CArchive& ar);
};