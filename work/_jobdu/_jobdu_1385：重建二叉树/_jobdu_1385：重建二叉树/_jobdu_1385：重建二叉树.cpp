/************************************************************************/
/* 题目描述：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并输出它的后序遍历序列。

输入：
输入可能包含多个测试样例，对于每个测试案例，
输入的第一行为一个整数n(1<=n<=1000)：代表二叉树的节点个数。
输入的第二行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的前序遍历序列。
输入的第三行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的中序遍历序列。
输出：
对应每个测试案例，输出一行：
如果题目中所给的前序和中序遍历序列能构成一棵二叉树，则输出n个整数，代表二叉树的后序遍历序列，每个元素后面都有空格。
如果题目中所给的前序和中序遍历序列不能构成一棵二叉树，则输出”No”。
样例输入：
8
1 2 4 7 3 5 6 8
4 7 2 1 5 3 8 6
8
1 2 4 7 3 5 6 8
4 1 2 7 5 3 8 6
样例输出：
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