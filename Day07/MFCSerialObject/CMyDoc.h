#pragma once
#include<afxwin.h>

/*
* ���Ա����л�����
*/
class CMyDoc : public CDocument {
	_DECLARE_DYNCREATE(CMyDoc);//��̬�������Ƶ�������
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc*& pOb);//���������غ���

public:
	int m_age;
	float m_score;
	CString m_name;

public:
	CMyDoc(int age = 0, float score = 0.0, CString name = "");
	virtual void Serialize(CArchive& ar);
};