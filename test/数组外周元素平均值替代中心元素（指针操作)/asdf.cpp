#include <iostream>
using namespace std;
float LongLine(float *p);
float ShortLine(float *p);
void main ()
{
	float sum=0,a[5][5];
	int i,j,index;
	float ave;
	float *p = *a;
	cout<<"输入数组元素，按行读取。"<<endl;
	for( i = 0;i<5;i++)
		for(j=0;j<5;j++)
			a[i][j] = i+j;
		//	cin>>a[i][j];
	sum += LongLine(p);
	for(i=0;i<3;i++)
		sum += ShortLine(p);
	sum += LongLine(p);
	ave = sum/16;
	p = *a;
	index = 2*5+(5/2+1)-1;
	for(j=0;j<index;j++)
		p++;
	*p = ave;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			cout<<"\t"<<a[i][j];
		cout<<endl;
	}
}
float LongLine(float *p)
{
	int temp = 0;
	for(int i=0;i<5;i++)
	{
		temp += *p;
		p++;
	}
	return temp;
}
float ShortLine(float *p)
{
	int temp = 0;
	temp += *p;
	int i=3;
	while(i--)
		p++;
	temp += *p;
	return temp;
}
