#include<iostream>
using namespace std;
class object
{
public:
	object(){cout<<"constructor object"<<endl;}
	~object(){cout<<"deconstructor object"<<endl;}
};
class objectk
{
public:
	objectk(){cout<<"constructor objectk"<<endl;}
	~objectk(){cout<<"deconstructor objectk"<<endl;}
};
class Bclass1
{
public:
	Bclass1(){cout<<"constructor Bclass1"<<endl;}
	~Bclass1(){cout<<"deconstructor Bclass1"<<endl;}
};
class Bclass2
{
public:
	Bclass2(){cout<<"constructor Bclass2"<<endl;}
	~Bclass2(){cout<<"deconstructor Bclass2"<<endl;}
};
class Bclass3
{
public:
	Bclass3(){cout<<"constructor Bclass3"<<endl;}
	~Bclass3(){cout<<"deconstructor Bclass3"<<endl;}
};
class Dclass:public Bclass1,virtual Bclass3,virtual Bclass2
{
	objectk k;object obj;
public:
	Dclass():obj(),k(),Bclass2(),Bclass3(),Bclass1(){cout<<"派生类建立"<<endl;}
	~Dclass(){cout<<"派生类析构"<<endl;}
};
int main()
{
	Dclass dd;
	cout<<"主程序运行"<<endl;
	return 0;
}
	