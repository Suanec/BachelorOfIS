#include"iostream"
using namespace std;
#include<string>
#include<math.h>

const int sign=-100000000;
int array[100][100];
double max=0;

int load(int width=0,int hight=0)
{
	cout<<"please input the width and the hight of the array";
	cin>>width>>hight;
	cout<<"the width of the box is:"<<width<<endl;
	cout<<"the hight of the box is:"<<hight<<endl;
	for(int i=hight;i>0;i--)
	{for(int j=width;j>0;j--)
		{cin>>array[i][j];}
	}
	cout<<"the array is:"<<endl;
	for(i=hight;i>0;i--)
	{for(int j=width;j>0;j--)
		{cout<<array[i][j]<<" ";}
	cout<<"\n";
	}
		return 0;
}

double MAX ( double a1,double a2,double a3,double a4,double a5)
{
	double a=(a1>a2)?(a1):(a2);
	double b=(a3>a4)?(a3):(a4);
	double c=(a>b)?a:b;
	return (c>a5)?c:(a5);
}


int fun(int x,int y)
{
	if(!y)max=0;
	


int main()
{
	int m,n;int a,s,d,f,g;
	//load(m,n);
	cin>>a>>s>>d>>f>>g;
	cout<<MAX(a,s,d,f,g);
	int dir;
	return 0;
}