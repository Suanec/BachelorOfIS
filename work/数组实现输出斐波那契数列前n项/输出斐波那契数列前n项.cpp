#include<iostream>
using namespace std;


void main()
{
	int quit=1;
	while(quit)
	{
		int m;
		cout<<"������쳲��������������е�����m��"<<endl;
		cin>>m;
		int a[100];
		int one,two;
		one=1;
		two=1;
		a[0]=a[1]=one;
		int i;
		for(i=2;i<m;i++)
		{
	
			if(i%2)
			{
				two=one+two;
				a[i]=two;
			}
			else
			{	
				one=one+two;
				a[i]=one;
			}
		}
		cout<<"쳲��������е�ǰ"<<m<<"��ֱ�Ϊ"<<endl;
		int j=0;
		while(j<m)
		{	
			cout<<a[j]<<endl;
			j++;
		}

		cout<<"input number except zero to continue,zero to exit:"<<endl;
		cin>>quit;
	}
}