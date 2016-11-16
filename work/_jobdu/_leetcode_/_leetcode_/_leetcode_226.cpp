/*
226. Invert Binary Tree   My Submissions QuestionEditorial Solution
Total Accepted: 88221 Total Submissions: 194202 Difficulty: Easy
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

#include"leetcode.h"



class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
		if(!root->left && !root->right) return root;
		//if(!root->left || !root->right) {
		//	TreeNode* p = root->right;
		//	root->right = root->left;
		//	root->left = p;
		//	return root;
		//}
		TreeNode *p = root->right;
		root->right = invertTree(root->left);
		root->left = invertTree(p);
		return root;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
