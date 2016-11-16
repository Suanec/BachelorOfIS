/*
160. Intersection of Two Linked Lists   My Submissions QuestionEditorial Solution
Total Accepted: 71622 Total Submissions: 236700 Difficulty: Easy
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include"leetcode.h"

class Solution {
public:
	int getLenth( ListNode * head ){
		int cnt = 0;
		ListNode* p = head;
		while(p){
			cnt++;
			p = p->next;
		}
		return cnt;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *res = NULL, *pa = headA, *pb = headB;
		if( !pa || !pb ) return res;
		int acnt = getLenth( headA );
		int bcnt = getLenth( headB );
		if( acnt > bcnt ) {
			int cnt = acnt - bcnt;
			while(cnt--) pa = pa->next;
		}
		else if( bcnt > acnt ){
			int cnt = bcnt - acnt;
			while(cnt--) pb = pb->next;
		}
		while( pa && pb && pa != pb ){
			pa = pa->next;
			pb = pb->next;
		}
		if( !(pa-pb) ) res = pa;
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[] = {1,3,5,7,9,11,13,15,17,19,21};
//	ListNode* headA = new ListNode(a[0]);
//	ListNode* p = headA;
//	for( int i = 1; i < 11; i++ ) {
//		p->next = new ListNode(a[i]);
//		p = p->next;
//	}
//	ListNode* headB = new ListNode(2);
//	slt.getIntersectionNode(headA,headB);
// 	//system("pause");
//}
