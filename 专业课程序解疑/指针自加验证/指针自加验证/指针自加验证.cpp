#include<iostream>
using namespace std;
void main()
{
	int arr[]={6,7,8,9,10};
	int * p = arr;
	*(p++)+=123;
	cout<<*p<<endl;
	cout<<*(++p)<<endl;
	cout<<arr[0]<<endl;
	p=(int*)(&arr+1);
	cout<<"*(arr+1)="<<*(arr+1)<<endl;
	cout<<"*(p-1)="<<*(p-1)<<endl;
	system("pause");
}
