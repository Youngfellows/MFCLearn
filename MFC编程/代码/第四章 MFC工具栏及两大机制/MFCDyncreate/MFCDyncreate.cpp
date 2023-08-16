#include <afxwin.h>
#include <iostream>
using namespace std;
class CAnimal : public CObject{
	DECLARE_DYNAMIC( CAnimal )
};
IMPLEMENT_DYNAMIC( CAnimal, CObject )
class CDog : public CAnimal{
//	DECLARE_DYNCREATE( CDog )
public: 
	static const CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 
	static CObject* PASCAL CreateObject();
};
//IMPLEMENT_DYNCREATE( CDog, CAnimal )
CObject* PASCAL CDog::CreateObject() 
{ 
	return new CDog; 
} 
AFX_COMDAT const CRuntimeClass CDog::classCDog = { 
		"CDog", 
		sizeof(class CDog), 
		0xFFFF, 
		CDog::CreateObject, 
		RUNTIME_CLASS(CAnimal), 
		NULL, 
		NULL 
}; 
CRuntimeClass* CDog::GetRuntimeClass() const 
{ 
	return RUNTIME_CLASS(CDog);
}

int main(){
	CObject* pob = RUNTIME_CLASS(CDog)->CreateObject( );//对象加工厂
	if( pob ){
		cout << pob << endl;
	}else{
		cout << "对象创建失败" << endl;
	}
	return 0;
}