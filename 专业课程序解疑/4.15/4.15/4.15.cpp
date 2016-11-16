#include<iostream>
using namespace std;
class B1
{
	int b1;
public:
	B1(int i){b1=i;cout<<"Constructor B1."<<endl;}
	void print(){cout<<b1<<endl;}
};
class B2
{
	int b2;
public:
	B2(int i){b2=i;cout<<"Constructor B2."<<endl;}
	void print(){cout<<b2<<endl;}
};
class B3
{
	int b3;
public:
	B3(int i){b3=i;cout<<"Constructor B3."<<endl;}
	int getb3(){return b3;}
};
class A:public B2,public B1
{
	int a; B3 bb;
public:
	A(int i,int j,int k,int l):B1(i),B2(j),bb(k)
	{
		a=l;
		cout<<"Constructor A."<<l<<endl;
	}
	void print()
	{
		B1::print();
		B2::print();
		cout<<a<<","<<bb.getb3()<<endl;
	}
};
void main()
{
	A aa(1,2,3,4);
	aa.print();
	system("pause");
}