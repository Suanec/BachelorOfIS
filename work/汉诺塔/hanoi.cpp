#include<iostream>
using namespace std;

void hanoi (int ,char, char,char);
int i;
void main()
{
	int q;
	while(q)
	{	
		i=0;
		cout<<"input the number of pans:"<<endl;
		int num;
		char x='x',y='y',z='z';
		cin>>num;
		hanoi(num,x,y,z);
		cout<<"there is "<<i<<" times move at finally."<<endl;
		cout<<"input number except zero to continue,zero to exit:"<<endl;
		cin>>q;
	}
}

void hanoi (int n,char x,char y,char z)
{
	if(n>0)
	{
		hanoi (n-1,x,z,y);
		cout<<x<<" -> "<<z<<endl;i++;
		hanoi(n-1,y,x,z);
	}
}

// 2的n次方减一。其中n为盘子数目。
// 则时间复杂度为2的n次方。