/*
2. Add Two Numbers   My Submissions QuestionEditorial Solution
Total Accepted: 140310 Total Submissions: 608245 Difficulty: Medium
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include"leetcode.h"



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
		if(!l1 && l2) return l2;
		if(l1 && !l2) return l1;
		int added = 0, tem = 0;
		ListNode *p1 = l1, *p2 = l2;
		tem = p1->val + p2->val + added;
		p1->val = tem % 10;
		p2->val = tem % 10;
		added = tem/10;
		while( p1->next && p2->next ){
			tem = p1->next->val + p2->next->val + added;
			p1->next->val = tem % 10;
			p2->next->val = tem % 10;
			added = tem/10;
			p1 = p1->next;
			p2 = p2->next;
		}
		/// both list empty
		if( !p1->next && !p2->next ) {
			if(added) p1->next = new ListNode(added);
			return l1;
		}
		/// l1 remains elements
		if( p1->next ) {
			/// added have num to plus is to prevent forget added at tail
			while(added){
				tem = p1->next->val + added;
				p1->next->val = tem % 10;
				added = tem / 10;
				p1 = p1->next;
				/// while added have and p1 is the tail
				/// have added To prevent add useless zero
				/// p1 tail is to prevent the pointer is NULL;
				if( added && !p1->next ) {
					p1->next = new ListNode(added);
					added = 0;
				}
			}
			return l1;
		}
		if( p2->next ){
			while(added){
				tem = p2->next->val + added;
				p2->next->val = tem % 10;
				added = tem / 10;
				p2 = p2->next;
				if( added && !p2->next ) {
					p2->next = new ListNode(added);
					added = 0;
				}
			}
			return l2;
		}
		return l1;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	ListNode* l1 = new ListNode(9);
//	l1->next = new ListNode(8);
//	ListNode* l2 = new ListNode(1);
//	//l2->next = new ListNode(0);
//	slt.addTwoNumbers(l1,l2);
// 	//system("pause");
//}
