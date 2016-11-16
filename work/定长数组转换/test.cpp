#include <iostream>
using namespace std;
#define m 173
#define n 5
void main ()
{
	int /*n = 5,*/i = 0;/*m = 80,*/
	cout<<"input the number of data."<<endl;
	//cin>>m;
	//int *a = new int(m);
	int a[m];
	for(i=0;i<m;i++)
	{
		//cout<<"input the data:"<<i<<endl;
		//cin>>a[i];
		a[i] = i;
	}
	cout<<"input the n."<<endl;
	//cin>>n;
	//int *b = new int(m);
	int b[m];//结果数组。
	int left = m%n;//最后一行的列数。
	for(i = 0;i < m;i++)
	{
		if(!left) b[(m/n)*(i%n)+(i/n)] = a[i];//最末行已满
		else if((i%n)<left)b[(m/n+1)*(i%n)+(i/n)] = a[i];//最末行未满且当前列有元素
		else b[(m/n)*(i%n)+left+(i/n)] = a[i];//最末行未满且当前列无元素。
	}
	cout<<(m/n)*(2%n)+2/n+1<<endl;
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<",";
		if(!(i%10)&&i)cout<<endl;

	}
	system("pause");
}
