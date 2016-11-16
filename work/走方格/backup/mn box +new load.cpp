#include"iostream"
using namespace std;
#include<string>
#include<math.h>
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
	int max=0;
	cout<<"jjj";
	if(x<0||x>m||(y==0&&x>=0&&x<=m&&x!=m/2+1))
	{
		cout<<"kkkkk";
		return sign;
	}
	else
	{
		max=MAX(fun(x+2,y-1),fun(x+1,y-1),fun(x,y-1),fun(x-1,y-1),fun(x-2,y-1))+array[x][y];
	cout<<"lll";
	return max;
	}
}



int main()
{


	int g;
	load(m,n);
//	fun(m,n);
	//cin>>a>>s>>d>>f>>g;
	//cout<<MAX(a,s,d,f,g);
	//int dir;
	return 0;
}