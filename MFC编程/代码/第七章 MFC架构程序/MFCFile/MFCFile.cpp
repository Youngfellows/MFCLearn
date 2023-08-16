#include <afxwin.h>
#include <iostream>
using namespace std;
void File( ){
	CFile file;
	file.Open( "E:/MFC/Day07/file.txt", CFile::modeCreate|CFile::modeReadWrite );
	char str[] = "hello file";
	file.Write( str, strlen(str) );
	file.SeekToBegin( );
	char buf[256] = { 0 };
	long nLen = file.Read( buf, 255 );
	cout << buf << ' ' << nLen << endl;
	file.Close( );
}
int main(){
	File( );
	return 0;
}