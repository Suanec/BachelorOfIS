#include"iostream"
using namespace std;
#include<iomanip>
int m=0,n=0;

const int sign=-100000000;
int array[100][100];


int load(int &width,int &hight)
{
	cout<<"please input the width and the hight of the array"<<endl;
	cin>>width>>hight;
	cout<<"the width of the box is:"<<width<<endl;
	cout<<"the hight of the box is:"<<hight<<endl;
	for(int i=1;i<=hight;i++)
	{
		for(int j=1;j<=width;j++)
		{cin>>array[i][j];}
	}

	for(i=1;i<=width;i++)array[hight+1][i]=sign;
	array[hight+1][width/2+1]=0;

	cout<<"the array is:"<<endl;
	for(i=1;i<=hight+1;i++)
	{
		for(int j=1;j<=width;j++)
		{
			if(array[i][j]==sign)cout<<setw(7)<<"*"<<"\t";
			else if(i==hight+1&&j==width/2+1) cout<<setw(7)<<"ÈË"<<"\t";
			else cout<<setw(7)<<array[i][j]<<"\t";
		}
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
	int max=0;
	if(y==0) return 0;
	else if(x<1||x>m)
	{
		return sign;
	}
	else
	{
		max=MAX(fun(x+2,y-1),fun(x+1,y-1),fun(x,y-1),fun(x-1,y-1),fun(x-2,y-1))+array[y][x];
		return max;
	}
}



int main()
{
	int g=0;
	load(m,n);
	g=fun(m/2+1,n+1);
	cout<<g<<endl;
	return 0;
}