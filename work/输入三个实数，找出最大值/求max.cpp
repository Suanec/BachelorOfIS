#include<iostream>
using namespace std;

float max (float,float,float);
main()
{
	int quit;
	while(quit)
	{
		float a,b,c,result;
		cout<<"please input three numbers need to manage:"<<endl;
		cin>>a>>b>>c;
		result=max(a,b,c);
		cout<<"the max number in these numbers is:";
			cout<<result<<endl;
		cout<<"input any number except zero to continue,zero to exit:"<<endl;
		quit--;
		cin>>quit;
	}
}
float max (float a,float b,float c)
{
	if(a>b)
	{
		if(a>c)return a;
		else return c;
	}
	else
	{
		if(b>c)return b;
		else return c;
	}
}
