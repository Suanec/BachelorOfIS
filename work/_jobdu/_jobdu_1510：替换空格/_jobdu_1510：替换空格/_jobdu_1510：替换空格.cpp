/************************************************************************/
/*��Ŀ������
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
���룺
ÿ�������ļ�������һ�����������
����ÿ����԰���������һ�д���Ҫ������ַ�����
�����
��Ӧÿ�����԰������������������ַ�����
�������룺
We Are Happy
���������
We%20Are%20Happy                                                                      */
/************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string gStrIn;
	string gStrSource;
	string gStrResult;
	char   gChar;
	int    i = 0;
	while(scanf("%c", &gChar) != EOF )
	{
		if(' ' == gChar)
			gStrResult += "%20";
		else gStrResult += gChar;
	}
	cout<<gStrResult<<endl;
	gStrResult.clear();
	return 1;
}
