#include<iostream>
using namespace std;
//////////////////////////////////////��
//����ָ�����ָ����������󣬵����ܷ�����������������Ա��//
 class A 
{
public:
	void virtual show1(){cout<<"show1"<<endl;}
};
class B:public A
{
public:
	void show1(){cout<<"Bshow1"<<endl;}
	void show2(){cout<<"show2"<<endl;}
};
void main()
{
	A *p;
	p=new B;
	p->show1();
	system("pause");
}*/
