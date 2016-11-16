#include<iostream>
# include <stdio.h>

using namespace std;
struct S
{
	int i;
	int *p;
};
void main()
{
	S s;
	int *p = &s.i;
	p[0] = 1;
	p[1] = 5;
	cout<<"p[0] = "<<p[0]<<";"<<"s.i = "<<s.i<<endl;
	cout<<"&p[0] = "<<&p[0]<<";&s.i = "<<&s.i<<endl;
	cout <<"p[1] = " <<p[1]<<"; s.p = "<<s.p<<" "<<endl;
	cout<<"&p[1] = "<<&p[1]<<";&s.p =  "<<&s.p<<";&s.p[1] = "<<&s.p[1]<<endl;
	cout << endl;
	s.p = p;
	cout<<"p[0] = "<<p[0]<<";s.i = "<<s.i<<endl;
	cout<<"&p[0] = "<<&p[0]<<";&s.i = "<<&s.i<<endl;
	cout<<"p[1] = "<<p[1]<<";s.p = "<<s.p<<";s.p[1] = "<<s.p[1]<<endl;
	cout<<"&p[1] = "<<&p[1]<<";&s.p = "<<&s.p<<";&s.p[1] = "<<&s.p[1]<<endl;
	s.p[1] = 1;
	cout<<"s.p = "<<s.p<<";&s.p = "<<&s.p<<endl;

/*	char fn=NULL, ln = NULL;
	printf("请输入第一个字母：\n");
		scanf("%c", &ln);
		printf("输出第一个字母：%c\n", ln);
		printf("请输入第二个字母：\n");
		scanf("%c", &fn);cout<<"<<";
		cin>>fn;scanf("%c", &fn);cout<<">>";
		printf("输出第二个字母：%c\n", fn);
		cout<<&fn<<" "<<&ln<<endl;
		char *p123,*q123;
		p123=&fn;
		q123=&ln;
		cout<<&p123<<" "<<&q123<<endl;
		int f=sizeof("\n");
		cout<<f<<endl;
		f=sizeof("123");
		cout<<f<<endl;*/
		int a=1024,b=1;
		int z=1024<<2;
		cout<<z<<endl;//z=4096
	system("pause");
}