/************************************************************************/
/* ��Ŀ������
��������С��10000��������A��B������A+B����Ҫע����ǣ����A��B��ĩβK��������8��λ������ͬ����ֱ�����-1��
���룺
��������������ɲ���������ÿ����������ռһ�У���ʽΪ"A B K"��������������һ���ո�������A��BͬʱΪ0ʱ�����������Ӧ�Ľ����Ҫ�����
�����
��ÿ�������������1�У���A+B��ֵ������-1��
�������룺
1 2 1
11 21 1
108 8 2
36 64 3
0 0 1
���������
3
-1
-1
100                                                                     */
/************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	short aPlus,bPlus,divTem,k;
	short sum;
	int i ;
	i = 0;
	divTem = 1;
	while(cin>>aPlus)
	{
		cin>>bPlus;
		cin>>k;
		if(!aPlus&&!bPlus)break;
		i = k;
		while(i)
		{
			divTem *= 10;
			if(aPlus%divTem != bPlus%divTem) break;
			i--;
		}
		if(!i)
		{
			sum = -1;
			cout<<sum<<endl;
			divTem = 1;
		}
		else
		{
			sum = aPlus + bPlus;
			cout<<sum<<endl;
			sum = 0;
			divTem = 1;
		}
	}
	return 0;
}