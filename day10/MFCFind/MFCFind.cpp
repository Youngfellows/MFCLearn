
#include <afxwin.h>
#include <iostream>
#include "MFCFind.h"

using namespace std;

int main(int argc, char* argv[])
{
	CString dirname = "D:/UML";//目录名
	Find(dirname);
	return 0;
}

/*
* 查找遍历文件夹
*/
void Find(CString path)
{
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//文件搜索对象
	BOOL goFind = find.FindFile(strPath);//
	while (goFind)
	{
		goFind = find.FindNextFile();//找到当前文件，将文件信息保存find对象的成员变量中
		CString filename = find.GetFileName();
		CString filepath = find.GetFilePath();
		if (find.IsDirectory() && !find.IsDots())
		{
			std::cout << "[" << filename << "]" << std::endl;
			Find(filepath);//递归
		}
		else {
			std::cout << filename << std::endl;
		}
	}
	find.Close();
}

