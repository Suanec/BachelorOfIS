/*
98. Validate Binary Search Tree   My Submissions QuestionEditorial Solution
Total Accepted: 90825 Total Submissions: 433733 Difficulty: Medium
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include"leetcode.h"

class Solution {
public:
	void inorder( TreeNode* root, vector<int> & vec ) {
		if( !root ) return ;
		if( !root->left && ! root->right ) vec.push_back(root->val);
		else{
			inorder( root->left, vec );
			vec.push_back( root->val );
			inorder( root->right, vec );
		}
	}
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
		inorder( root, vec );
		for( int i = 1; i < vec.size(); i++ ){
			if( vec[i] <= vec[i-1] ) return false;
		}
		return true;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
