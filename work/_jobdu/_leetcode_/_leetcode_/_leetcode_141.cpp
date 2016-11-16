/*
141. Linked List Cycle   My Submissions QuestionEditorial Solution
Total Accepted: 103411 Total Submissions: 280234 Difficulty: Easy
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include"leetcode.h"



class Solution {
public:
	/// 56ms
  //  bool hasCycle(ListNode *head) {
		//if( !head || !head->next ) return false;
		//map<ListNode*,int> m;
		//ListNode* p = head;
		//while( p ){
		//	if( m.find(p) == m.end() ) m[p]++;
		//	else return true;
		//	p = p->next;
		//}
		//return false;
  //  }
	/// 12ms
	bool hasCycle(ListNode *head) {
		if( !head || !head->next ) return false;
		ListNode* p = head, *q = head;
		while( p && p->next ){
			q = q->next;
			p = p->next->next;
			if( !(p-q) ) return true;
		}
		return false;
    }

};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
