/*
100. Same Tree   My Submissions QuestionEditorial Solution
Total Accepted: 126467 Total Submissions: 292633 Difficulty: Easy
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

#include"leetcode.h"



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
		if((p && !q)||(q && !p)) return false;
		if( p->val - q->val )return false;
		return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
