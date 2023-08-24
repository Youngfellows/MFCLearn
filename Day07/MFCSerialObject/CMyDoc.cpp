#include "CMyDoc.h"

IMPLEMENT_SERIAL(CMyDoc, CDocument, 1)
/*
��̬��������ʵ�ֺ�վ�����Ķ���
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
		ar << this->m_age << this->m_score << this->m_name; //���л��������ͱ���  
	}
	else {
		ar >> m_age >> m_score >> m_name;//�����л��������ͱ���
	}
}


