
#include <afxwin.h>
#include <iostream>
#include "MFCFind.h"

using namespace std;

int main(int argc, char* argv[])
{
	CString dirname = "D:/UML";//Ŀ¼��
	Find(dirname);
	return 0;
}

/*
* ���ұ����ļ���
*/
void Find(CString path)
{
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//�ļ���������
	BOOL goFind = find.FindFile(strPath);//
	while (goFind)
	{
		goFind = find.FindNextFile();//�ҵ���ǰ�ļ������ļ���Ϣ����find����ĳ�Ա������
		CString filename = find.GetFileName();
		CString filepath = find.GetFilePath();
		if (find.IsDirectory() && !find.IsDots())
		{
			std::cout << "[" << filename << "]" << std::endl;
			Find(filepath);//�ݹ�
		}
		else {
			std::cout << filename << std::endl;
		}
	}
	find.Close();
}

