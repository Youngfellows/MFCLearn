#include "MFCSerialObject.h"
#include "CMyDoc.h"
#include <iostream>

using namespace std;

/*
* 函数声明: 序列化（存储、写）数据
*/
void Store()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serialobject.txt";
	file.Open(filename, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//归档类对象,维护缓冲区。
	CMyDoc data(18, 88.5, "xiaolongnv");
	ar << &data; //序列化对象，就是将对象的各个成员变量序列化。
	ar.Close();
	file.Close();
}


/*
* 函数声明: /反序列化（加载/读）
*/
void Load()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serialobject.txt";
	file.Open(filename, CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//维护一个buff，大小4096字节
	CMyDoc* pdata = NULL;
	ar >> pdata;
	ar.Close();
	file.Close();
	cout << pdata->m_age << " " << pdata->m_score << " " << pdata->m_name << endl;
}
