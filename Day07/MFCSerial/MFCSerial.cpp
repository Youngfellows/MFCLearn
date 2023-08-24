#include "MFCSerial.h"
#include <afxwin.h>
#include <iostream>

using namespace std;

/*
* ���л����洢��д������
*/
void Store()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serial.txt";
	file.Open(filename, CFile::modeCreate | CFile::modeWrite);//���ļ�
	CArchive ar(&file, CArchive::store, 4096);//�鵵�����,ά����������
	long age = 18;
	ar << age;//��18���浱ǰָ���λ�ã�������ƶ���ǰָ����Ӧ�ֽ�����
	float score = 88.5;
	ar << score;//��88.5���浱ǰָ���λ�ã�������ƶ���ǰָ����Ӧ�ֽ�����
	CString name = "yangguo";
	ar << name;
	ar.Close();
	file.Close();
}

/*
* �����л�������/����
*/
void Load()
{
	CFile file;
	const char* filename = "D:/StudyCode2021/MFCLearn/Day07/serial.txt";
	file.Open(filename, CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//ά��һ��buff����С4096�ֽ�
	long age;
	ar >> age;//�������л���һ������ʱ���ڲ����ļ����������ݶ���arά����buff��
	float score;
	ar >> score;//�������л���������ʱ�򣬲���Ҫ��Ӳ���ļ��ж�ȡ��ֱ�ӵ�arά����buff�ж�ȡ
	CString name;
	ar >> name;//�������л���������ʱ�򣬲���Ҫ��Ӳ���ļ��ж�ȡ��ֱ�ӵ�arά����buff�ж�ȡ
	ar.Close();
	file.Close();
	cout << age << " " << score << " " << name << endl;
}
