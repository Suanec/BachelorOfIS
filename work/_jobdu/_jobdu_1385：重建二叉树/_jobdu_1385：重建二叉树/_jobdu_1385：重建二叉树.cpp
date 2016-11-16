/************************************************************************/
/* ��Ŀ������
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ���������������ĺ���������С�

���룺
������ܰ��������������������ÿ�����԰�����
����ĵ�һ��Ϊһ������n(1<=n<=1000)������������Ľڵ������
����ĵڶ��а���n������(����ÿ��Ԫ��a�ķ�ΧΪ(1<=a<=1000))�������������ǰ��������С�
����ĵ����а���n������(����ÿ��Ԫ��a�ķ�ΧΪ(1<=a<=1000))�����������������������С�
�����
��Ӧÿ�����԰��������һ�У�
�����Ŀ��������ǰ���������������ܹ���һ�ö������������n������������������ĺ���������У�ÿ��Ԫ�غ��涼�пո�
�����Ŀ��������ǰ�������������в��ܹ���һ�ö��������������No����
�������룺
8
1 2 4 7 3 5 6 8
4 7 2 1 5 3 8 6
8
1 2 4 7 3 5 6 8
4 1 2 7 5 3 8 6
���������
7 4 2 5 8 6 3 1 
No                                                                     */
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int    m_value;
	node*  p_left;
	node*  p_right;
}NODE;

NODE * CreateTreeByPreMidArr(int _preArr[], int _preStart, int _preEnd,
	                         int _midArr[], int _midStart, int _midEnd)
{
	node *  pWork = new node;
	int  index = 0;
	if(_preStart == _preEnd && _midStart == _midEnd )
	{
		pWork->m_value = _preArr[_preStart];
		pWork->p_left = pWork->p_right = NULL;
		return pWork;
	}
	else if(_preStart-_preEnd == _midStart - _midEnd)
	{
		index = _midStart;
		while(_preArr[_preStart] != _midArr[index])
			index++;
		pWork->m_value = _preArr[_preStart];
		pWork->p_left = CreateTreeByPreMidArr(_preArr,_preStart+1,_preStart+(index-_midStart),
			                                  _midArr,_midStart,index-1);
		pWork->p_right = CreateTreeByPreMidArr(_preArr,_preStart+(index-_midStart)+1,_preEnd,
			                                   _midArr,index+1,_midEnd);
		return pWork;
	}
	else return NULL;
}

void AfterOrder(node* _Tree)
{
	if(!_Tree)return ;
	AfterOrder(_Tree->p_left);
	AfterOrder(_Tree->p_right);
	printf("%d",_Tree->m_value);
}
int main()
{
	//int preArr[1024];
	//int midArr[1024];
	int g_intNum = 0;
	int i = 0;
	NODE* T = NULL;
	//while(scanf("%d",&g_intNum)!=EOF)
	//{
	//	for( i = 0; i<g_intNum; i++)
	//		scanf("%d",&preArr[i]);
	//	for( i = 0; i<g_intNum; i++)
	//		scanf("%d",&midArr[i]);
	//}
	g_intNum = 8;
	int preArr[] = {1,2,4,7,3,5,6,8};
	int midArr[] = {4,7,2,1,5,3,8,6};
	T = CreateTreeByPreMidArr(preArr,0,g_intNum-1,midArr,0,g_intNum-1);
	AfterOrder(T);
	return 1;
}