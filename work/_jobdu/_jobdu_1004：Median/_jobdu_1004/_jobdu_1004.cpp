/************************************************************************/
/* 题目描述：
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the non-decreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
输入：
Each input file may contain more than one test case.
Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤1000000) is the size of that sequence. Then N integers follow, separated by a space.
It is guaranteed that all the integers are in the range of long int.
输出：
For each test case you should output the median of the two given sequences in a line.
样例输入：
4 11 12 13 14
5 9 10 15 16 17
样例输出：
13                                                                     */
/************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct NODE
{
    long val;
    NODE * next;
}TN;

typedef struct LNode
{
	TN    * data;
	LNode * next;
}LN; 
void InsertSort( TN * _List , long _val)
{

	TN * p = new TN ;
	p->val = _val;
	p->next = NULL;
	TN * q = _List;
	while(q->next&&(q->val <_val ))
		q = q->next;
	if(q->val>_val)
	{
		p->next = q->next;
		int temp = p->val;
		p->val = q->val ;
		q->val = temp;
		q->next = p;
	}
	else if(!q->next)
	{
		q->next = p;
	}
	else
	{
		p->next = q->next;
		int temp = q->val;
		q->val = p->val;
		p->val = temp;
		q->next = p;
	}
}/// InsertSort

int main()
{
    TN *aQueen,*bQueen,*pt,*pi,*pj;
	TN * s_gResult;
    int  aN, bN, index ,i,s_gSum;
    long temp;
	s_gResult = new TN;
	s_gResult->val = 0;
	s_gResult->next = NULL;
	aQueen = new TN;
	aQueen->next = NULL;
	bQueen = new TN;
	bQueen->next =NULL;
	aN = bN = index = 0;
	pt = NULL;
	temp = 0;

    while(cin>>aN)
    {
		
		for(i=0; i<aN; i++)
        {
            if(!aQueen->next)
            {
                aQueen->next = new TN;
                pt = aQueen->next;
            }
            cin>>temp;
            pt->val = temp;
            pt->next = new NODE;
            pt->next =NULL;
			InsertSort(s_gResult,temp);
        }
        cin>>bN;
        for(i=0; i<bN; i++)
        {
            if(!bQueen->next)
            {
                bQueen->next = new TN;
                pt = bQueen->next;
            }
            cin>>temp;
            pt->val = temp;
            pt->next = new NODE;
            pt->next = NULL;
			InsertSort(s_gResult,temp);
        }		

		s_gSum = aN+bN ;
		if(s_gSum%2)
		{
			s_gSum = s_gSum/2;
		}
		else
		{
			s_gSum /= 2;
			s_gSum--;
		}
		pt = s_gResult->next;
		while(s_gSum--)
			pt = pt->next;
		cout<<pt->val<<endl;

		temp = 0;
		pi = aQueen;
		while(pi->next)
		{
			pj = pi;
			pi = pi->next;
			free(pj);
		}
		free(pi);
		pi = bQueen;
		while(pi->next)
		{
			pj = pi ;
			pi = pi->next;
			free(pj);
		}
		free(pi);
		pi = s_gResult;
		while(pi->next)
		{
			pj = pi ;
			pi = pi->next;
			free(pj);
		}
		free(pi);
		temp = 0;
		aN = bN = i = index = 0;
		pt = pi = pj = NULL;
		s_gResult = new TN;
		s_gResult->val = 0;
		s_gResult->next = NULL;
		aQueen = new TN;
		aQueen->next = NULL;
		bQueen = new TN;
		bQueen->next =NULL;
		aN = bN = index = 0;
		pt = NULL;
		temp = 0;

    }
    return 1;
}