#include "MFCSerialObject.h"
#include "CMyDoc.h"
#include <iostream>

using namespace std;

/*
* ��������: ���л����洢��д������
*/
void Store()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serialobject.txt";
	file.Open(filename, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//�鵵�����,ά����������
	CMyDoc data(18, 88.5, "xiaolongnv");
	ar << &data; //���л����󣬾��ǽ�����ĸ�����Ա�������л���
	ar.Close();
	file.Close();
}


/*
* ��������: /�����л�������/����
*/
void Load()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serialobject.txt";
	file.Open(filename, CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//ά��һ��buff����С4096�ֽ�
	CMyDoc* pdata = NULL;
	ar >> pdata;
	ar.Close();
	file.Close();
	cout << pdata->m_age << " " << pdata->m_score << " " << pdata->m_name << endl;
}
