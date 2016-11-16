#include"iostream"
using namespace std;
#include<string>
#include<math.h>

const int sign=-100000000;
int array[100][100];

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

int main()
{
	int m,n;
	load(m,n);
	return 0;
}