#include<afxwin.h>
#include<iostream>
#include "MFCFile.h"

using namespace std;

void File()
{
	cout << "Hello Visual Studio" << endl;
	CFile file;
	const char* fileName = "D:/StudyCode2021/MFCLearn/Day07/file.txt";
	file.Open(fileName, CFile::modeCreate | CFile::modeReadWrite);//创建并打开文件
	char text[] = "Hello Visual Studio,Build MFC Application ...";
	file.Write(text, strlen(text));//向文件中写入数据
	file.SeekToBegin();

	char buf[256] = { 0 };//缓冲区
	long nLen = file.Read(buf, 255);//读取文件内容到缓冲区
	cout << "nLen:" << nLen << endl;
	cout << buf << endl;
	file.Close();//关闭文件
}