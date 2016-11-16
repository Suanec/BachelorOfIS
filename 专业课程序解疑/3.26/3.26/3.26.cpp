#include<iostream>
using namespace std;
class M{
	int A;
	static int B;
public:
	M(int a)
	{
		A=a;
		B+=a;
		cout<<"constructing"<<endl;
	}
	static void f1(M m);
	~M()
	{
		cout<<"destructing"<<endl;
	}
};
void M::f1(M m)
{
	cout<<"A="<<m.A<<endl;
	cout<<"B="<<B<<endl;
}
int M::B=0;
int main ()
{
	M P(5),Q(10);
	M::f1(P);
	M::f1(Q);
	//system("pause");
	return 0;
}
