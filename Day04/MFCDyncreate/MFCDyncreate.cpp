#include<afxwin.h>
#include<iostream>

using namespace std;

/*��̬�������Ƶ�ʹ��*/
class CAnimal : public CObject {
	DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal, CObject)

class CDog : public CAnimal {
	//DECLARE_DYNCREATE(CDog)
public:
	static const CRuntimeClass classCDog;
	virtual CRuntimeClass* GetRuntimeClass() const;
	static CObject* PASCAL CreateObject();
};

//IMPLEMENT_DYNCREATE(CDog, CAnimal)
CObject* PASCAL CDog::CreateObject()
{
	return new CDog;
}

AFX_COMDAT const CRuntimeClass CDog::classCDog = {
			"CDog",
			sizeof(class CDog),
			0xFFFF,
			CDog::CreateObject,
			//RUNTIME_CLASS(CAnimal),
			 ((CRuntimeClass*)(&CAnimal::classCAnimal)),
			NULL,
			NULL };

CRuntimeClass* CDog::GetRuntimeClass() const
{
	//return RUNTIME_CLASS(CDog);
	return ((CRuntimeClass*)(&CDog::classCDog));
}



int main(int argc, char* argv[])
{
	std::cout << "hello mfc dyncreate" << std::endl;
	//CObject* pob = RUNTIME_CLASS(CDog)->CreateObject();//����ӹ���
	CObject* pob = RUNTIME_CLASS(CAnimal)->CreateObject();//����ӹ���
	if (pob)
	{
		std::cout << pob << std::endl;
	}
	else
	{
		std::cout << "���󴴽�ʧ��" << std::endl;
	}

	return 0;
}