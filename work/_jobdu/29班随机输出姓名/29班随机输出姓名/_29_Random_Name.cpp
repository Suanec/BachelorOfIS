#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
using namespace std;
string nameArr[] = {
	"杨清章","王中宇","李美云","周家林",
	"冯春辉","申恩兆","陈思","李洋洋",
	"李鑫","曹迪","付卫兴","康西龙",
	"周杨","刘银超","张金钟","王永鹏",
	"程彦龙","刘晶","马晓阳","李丽霞",
	"王琼琼","周倩楠","马晓彤","许晨熙",
	"杨青青","房小温","陈晓娟","许翠",
	"范超智","刘真君","李卫超"};
int main()
{
	int i = 0;
	int valueName = 0;
	int valuePre  = 0;
	string strName;
	::srand(GetTickCount());
	while(1)
	{
		cout<<"press any button to get the random name :"<<endl;
		system("pause");
		valueName = ::rand()%31+1;
		while(valueName == valuePre)
			valueName = ::rand()%31+1;
		valuePre = valueName ;
		cout<<"\n\n\n\n\n\n\n\n---------------------------"<<nameArr[valueName-1]
		<<"---------------------------\n\n\n\n\n\n\n\n"<<endl;
	}
	return 0;
}