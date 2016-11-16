#include<iostream>
using namespace std;
//void f(int j);
class AA
{
public:
	AA(){cout<<"constructor of AA"<<endl;}
	virtual void fun(){cout<<"AA::fun() called"<<endl;}
};
class BB:public AA
{
public:
	BB(){cout<<"constructor default of BB"<<endl;}
	~BB(){cout<<"destructor"<<endl;}
	void fun(){cout<<"BB::fun() called"<<endl;}
};
void cal2(AA a)
{
	a.fun();
}
void cal1(BB b)
{
	b.fun();
}
int funtest(char * p)
{
	char str[100];
	p=str;
	return int(p);
}
int main ()
{
	BB b;
	cal1(b);
	cal2(b);
	void *p=malloc(100);
	cout<<sizeof(p)<<endl;
	char*q=NULL;
	funtest(q);
	cout<<sizeof(q)<<endl;
	char strl[100];
	cout<<sizeof(strl)<<endl;
	float *r;
	cout<<sizeof(r)<<endl;
	//for(int i=1;i<=4;i++)
	//	f(i);
	//int x=18;
	//do
	//{
	//	switch(x%2)
	//	{
	//	case 1: x--;break;
	//	case 0: x/=2;break;
	//	}
	//	x--;
	//	cout<<x<<endl;
	//}while(x>0);
	system("pause");
	return 0;
}
//void f(int j)
//{
//	static int a=2;
//	int b=1;
//	b++;
//	cout<<a<<"+"<<b<<"+"<<j<<"="<<a+b+j<<endl;
//	a+=10;
//}