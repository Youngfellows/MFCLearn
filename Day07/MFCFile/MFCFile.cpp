#include<afxwin.h>
#include<iostream>
#include "MFCFile.h"

using namespace std;

void File()
{
	cout << "Hello Visual Studio" << endl;
	CFile file;
	const char* fileName = "D:/StudyCode2021/MFCLearn/Day07/file.txt";
	file.Open(fileName, CFile::modeCreate | CFile::modeReadWrite);//���������ļ�
	char text[] = "Hello Visual Studio,Build MFC Application ...";
	file.Write(text, strlen(text));//���ļ���д������
	file.SeekToBegin();

	char buf[256] = { 0 };//������
	long nLen = file.Read(buf, 255);//��ȡ�ļ����ݵ�������
	cout << "nLen:" << nLen << endl;
	cout << buf << endl;
	file.Close();//�ر��ļ�
}