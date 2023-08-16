#include<afxwin.h>
#include<iostream>

using namespace std;

/*运行时类信息机制的使用*/
class CAnimal :public CObject {
	DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal, CObject)


class CDog : public CAnimal {
	//DECLARE_DYNAMIC(CDog)
public:
	static const CRuntimeClass classCDog;
	virtual CRuntimeClass* GetRuntimeClass() const;
};
//IMPLEMENT_DYNAMIC(CDog, CAnimal)
//IMPLEMENT_RUNTIMECLASS(CDog, CAnimal, 0xFFFF, NULL, NULL)
AFX_COMDAT const CRuntimeClass CDog::classCDog = {
		"CDog",
		sizeof(class CDog),
		0xFFFF,
		NULL,
		//RUNTIME_CLASS(CAnimal),
		((CRuntimeClass*)(&CAnimal::classCAnimal)),
		NULL,
		NULL };

CRuntimeClass* CDog::GetRuntimeClass() const
{
	//return RUNTIME_CLASS(CDog);
	return  ((CRuntimeClass*)(&CDog::classCDog));
}

int main(int argc, char* argv[])
{
	std::cout << "hello world" << std::endl;
	CDog yellowdog;
	//if (yellowdog.IsKindOf(RUNTIME_CLASS(CDog)))
	//if (yellowdog.IsKindOf(RUNTIME_CLASS(CAnimal)))
	//if (yellowdog.IsKindOf(RUNTIME_CLASS(CObject)))
	if (yellowdog.IsKindOf(RUNTIME_CLASS(CWnd)))
	{
		std::cout << "yellowdog is CWnd" << std::endl;
	}
	else
	{
		std::cout << "yellowdog is not CWnd" << std::endl;
	}
	return 0;
}