/*
206. Reverse Linked List   My Submissions QuestionEditorial Solution
Total Accepted: 106559 Total Submissions: 269215 Difficulty: Easy
Reverse a singly linked list.
*/


#include"leetcode.h"



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
		ListNode *pold = head->next;
		ListNode *res = head;
		res->next = NULL;
		ListNode *p = NULL;
		while( pold ){
			p = pold;
			pold = pold->next;
			p->next = res;
			res = p;
		}
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
