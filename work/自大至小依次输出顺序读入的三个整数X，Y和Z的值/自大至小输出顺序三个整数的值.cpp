#include<iostream>
using namespace std;

main()
{
	int quit=1;
	while(quit)
	{
		int m,n,k,max1,max2;
		int a[3];
		cout<<"please input the three numbers that need sort:"<<endl;
		cin>>m>>n>>k;
		if(m>n)
		{
			if(m>k)
			{
				a[0]=m;
				if(k>n){a[1]=k;a[2]=n;}
				else
				{
					a[1]=n;
					a[2]=k;
				}
			}
			else 
			{
				a[0]=k;
				a[1]=m;
				a[2]=n;
			}
		}
		else 
		{
			if (n>k)
			{
				a[0]=n;
				if (k>m)
				{
					a[1]=k;
					a[2]=m;
				}
				else
				{
					a[1]=m;
					a[2]=k;
				}
			}
			else
			{
				a[0]=k;
				a[1]=n;
				a[2]=m;
			}
		}
		for(int i=0;i<3;i++)
		{
			cout<<a[i]<<endl;
		}
		cout<<"input \"0\" to exit,input \"1\" to continue: "<<endl;
		cin>>quit;
	}
}
