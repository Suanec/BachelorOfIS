/////////////////////////////////////////////////////////////////////
//////				定长数组转换算法。o(n)、o(n).
//////				未实现指针实时创建数组并操作。
/////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
//#define m 173
//#define n 5
void main ()
{
	int m = 80,n = 5,i = 0;
	cout<<"input the number of data."<<endl;
	cin>>m;
	int *a = new int[m];
	for(i=0;i<m;i++)
	{
		//cout<<"input the data:"<<i<<endl;
		//cin>>a[i];
		a[i] = i;
	}
	cout<<"input the n."<<endl;
	cin>>n;
	int *b = new int[m];//结果数组。
	int left = m%n;//最后一行的列数。
	for(i = 0;i < m;i++)
	{
		if(!left) b[(m/n)*(i%n)+(i/n)] = a[i];//最末行已满
		else if((i%n)<left)b[(m/n+1)*(i%n)+(i/n)] = a[i];//最末行未满且当前列有元素
		else b[(m/n)*(i%n)+left+(i/n)] = a[i];//最末行未满且当前列无元素。
	}
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<",";
		if(!(i%10)&&i)cout<<endl;

	}
	system("pause");
}
