#include<iostream>
using namespace std;
char* GetMemory()
{
	char p[]="hello world";
	return p;
}
void TestMem(void)
{
	char *str=NULL;
	str = GetMemory();
	cout<<str<<endl;
}//ยาย๋
char* GetMemory1()
{
	char p[]="hello world";
	char * q=p;
	return q;
}
void TestMem1(void)
{
	char *str=NULL;
	str = GetMemory1();
	cout<<str<<endl;
}//ยาย๋
char* GetPointer()
{
	char *p="hello world";
	return p;
}
void TestPoint(void)
{
	char *str=NULL;
	str = GetPointer();
	cout<<str<<endl;
}//hello world
char& GetPname()
{
	char *p="hello world";
	char &t=*p;
	return t;
}
void TestPname(void)
{
	char *str=NULL;
	//*str = GetPname();
	cout<<GetPname()<<endl;
}//h
void GetMemory(char **p,int num)
{
	*p=(char*)malloc(num);
}
void TestMem(int m)
{
	char *str = NULL;
	GetMemory(&str,100);
	strcpy(str,"hello");
	cout<<str<<endl;
}//hello
void main()
{
	int m=100;
	TestMem();
	TestMem1();
	TestPoint();
	TestPname();
	TestMem(100);
	system("pause");
}