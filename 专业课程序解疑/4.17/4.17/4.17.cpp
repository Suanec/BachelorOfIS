#include<iostream>
using namespace std;
class A
{
	int a,b;
public:
	A(int i,int j)
	{
		a=i;b=j;
	}
	void Move(int x,int y)
	{
		a+=x;b+=y;
	}
	void Show()
	{
		cout<<"("<<a<<","<<b<<")"<<endl;
	}
};
class B:public A
{
	int x,y;
public:
	B(int i,int j,int k,int l):A(i,j)
	{
		x=k;y=l;
	}
	void Show()
	{
		cout<<x<<","<<y<<endl;
	}
	void fun()
	{
		Move(3,5);
	}
	void f1()
	{
		A::Show();
	}
};
void main()
{
	A e(1,2);
	e.Show();
	B d(3,4,5,6);
	d.fun();
	d.Show();
	d.f1();
	system("pause");
}