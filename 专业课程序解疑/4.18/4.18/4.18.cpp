#include<iostream>
using namespace std;
//一个类的某个基类是虚基类，则该类相对于其派生类也为虚基类
//构造函数调用顺序有变：将level1中base2的继承方式改为虚继承后，
//程序运行结果有变。

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