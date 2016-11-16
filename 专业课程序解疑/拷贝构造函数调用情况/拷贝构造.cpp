#include<iostream>
using namespace std;
class A 
{
public:
	A():i(5){cout<<"construct."<<endl;}
	A(int m):i(m){cout<<"construte."<<m<<endl;}
	A(A & a){ cout <<"copy construct."<<endl;}
	A f(A a){cout<<a.i<<endl;return a;}
	void g(int m){i=m;}
	int k(){return i;}
private:
	int i;
};
void main()
{
	cout<<"code-->A a;"<<endl;A a;
	cout<<"code-->cout<<a.k()<<endl;"<<endl;cout<<a.k()<<endl;
	cout<<"code-->A b(7);"<<endl;A b(7);
	cout<<"code-->cout<<b.k()<<endl;"<<endl;cout<<b.k()<<endl;
	cout<<"code-->a = b;"<<endl;a = b;
	cout<<"code-->cout<<\"a = b\"<<endl;"<<endl;	cout<<"a = b"<<endl;
	cout<<"code-->A c = b;"<<endl;A c = b;
	cout<<"code-->a.f(b);"<<endl;a.f(b);
	cout<<"code-->c.g(90);"<<endl;c.g(90);
	cout<<"code-->A d = a.f(c);"<<endl;A d = a.f(c);
	cout<<"code-->system(\"pause\");"<<endl;system("pause");
}
