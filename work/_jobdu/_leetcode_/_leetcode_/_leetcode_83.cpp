/*
83. Remove Duplicates from Sorted List   My Submissions QuestionEditorial Solution
Total Accepted: 115230 Total Submissions: 313077 Difficulty: Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include"leetcode.h"



class Solution {
public:
	/// 16ms
    ListNode* deleteDuplicates(ListNode* head) {
        if( !head ) return NULL;
		if( !head->next ) return head;
		ListNode *p = head, *q = NULL;
		while(p && p->next){
			if( p->val - p->next->val ) p = p->next;
			else{
				q = p->next;
				p->next = q->next;
				q->next = NULL;
				free(q);
			}
		}
		return head;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	ListNode*l = new ListNode(1);
//	l->next = new ListNode(1);
//	slt.deleteDuplicates(l);
// 	//system("pause");
//}
