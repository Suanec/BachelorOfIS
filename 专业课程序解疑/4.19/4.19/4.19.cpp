#include<iostream>
using namespace std;
#include<iomanip>
class table
{
	int ia,iz;
public:
	table(char s,char t){ia=int(s);iz=(int)t;}
	void ascii()
	{
		int k=1;
		for(int i=ia;i<=iz;i++)
		{
			cout<<setw(4)<<i<<"---->"<<char(i);
			if(!(k%7))cout<<endl;
			k++;
		}
		cout<<endl;
	}
};
class dur_table:public table
{
	char *s; 
public:
	dur_table(char a,char z,char *m):table(a,z) {s=m;}
	void print(void){cout<<s<<endl;table::ascii();}
};
void main ()
{
	dur_table ob( 'a','z',"ASCII value----char");
	ob.print();
	system("pause");
}