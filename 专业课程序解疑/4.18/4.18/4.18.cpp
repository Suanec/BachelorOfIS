#include<iostream>
using namespace std;
//һ�����ĳ������������࣬������������������ҲΪ�����
//���캯������˳���б䣺��level1��base2�ļ̳з�ʽ��Ϊ��̳к�
//�������н���б䡣

class base1
{
public:
	base1(){cout<<"class base1"<<endl;}
};
class base2
{
public:
	base2(){cout<<"class base2"<<endl;}
};
class level1:public base2,virtual public base1
{
public:
	level1(){cout<<"class level1"<<endl;}
};
class level2:public base2,virtual public base1
{
public:
	level2(){cout<<"class level2"<<endl;}
};
class toplevel:public level1,virtual public level2
{
public:
	toplevel(){cout<<"class toplevel"<<endl;}
};
void main ()
{
	toplevel obj;
	system("pause");
}