#include <iostream>
using namespace std;
class test
{
	int i;
public:
	test();
	~test(){};
};
test::test()
{
	i=25;
	for(int crt=0;crt<10;crt++)
	{
		cout<<"constructor test:"<<crt<<endl;
	}
}
test obj;
int main()
{
	system("pause");
	return 0;
}