#include "CMyDoc.h"

IMPLEMENT_SERIAL(CMyDoc, CDocument, 1)
/*
动态创建机制实现宏站出来的东西
CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc* &pOb)
{
	pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(CMyDoc));
			return ar;
}
*/

CMyDoc::CMyDoc(int age, float score, CString name) :
	m_age(age), m_score(score), m_name(name) {
}

void CMyDoc::Serialize(CArchive& ar) {
	if (ar.IsStoring()) {
		ar << this->m_age << this->m_score << this->m_name; //序列化基本类型变量  
	}
	else {
		ar >> m_age >> m_score >> m_name;//反序列化基本类型变量
	}
}


