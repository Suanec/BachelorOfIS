/************************************************************************/
/* ��Ŀ������
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
���룺
ÿ�������ļ�������һ�����������
ÿһ����԰����������У�ÿ��һ������0������������һ������Ľڵ㡣��һ���������һ���ڵ��ֵ���������ơ������뵽-1ʱ��������������ϡ�-1������������
�����
��Ӧÿ�����԰������Դ�β��ͷ��˳���������ÿ���ڵ��ֵ��ÿ��ֵռһ�С�
�������룺
1
2
3
4
5
-1
���������
5
4
3
2
1                                                                     */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int   m_value;
	node* next;
}NODE;
int main()
{
	NODE * pHead = new NODE;
	pHead->next = NULL;
	NODE * pWork = NULL;
	int  g_mIntValue = -1;
	while(scanf("%d",&g_mIntValue) != EOF)
	{
		if(-1 == g_mIntValue)
			break;
		pWork = new NODE;
		pWork->next = pHead->next;
		pHead->next = pWork;
		pWork->m_value = g_mIntValue ;		
	}
	pWork = pHead->next;
	while(pWork)
	{
		printf("%d \n",pWork->m_value);
		pWork = pWork->next;
	}
	pWork = pHead->next;
	while(pWork)
	{
		pHead->next = pWork->next;
		pWork->next = NULL;
		free(pWork);
		pWork = pHead->next;
	}
	free(pHead);
	pHead = pWork = NULL;
	return 1;
}