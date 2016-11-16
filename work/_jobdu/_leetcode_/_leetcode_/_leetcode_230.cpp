/*
230. Kth Smallest Element in a BST   My Submissions QuestionEditorial Solution
Total Accepted: 44359 Total Submissions: 118074 Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.


*/

#include"leetcode.h"
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
class Solution {
public:

	/// 24ms
	void MidRoot( TreeNode* root, vector<int>& vector ){
		if( !root ) return ;
		if( !root->left && !root->right ) vector.push_back(root->val);
		else{
			MidRoot( root->left, vector );
			vector.push_back( root->val );
			MidRoot( root->right, vector );
		}
	}
    int kthSmallest(TreeNode* root, int k) {
        if( !root ) return 0;
		vector<int> vec;
		MidRoot( root, vec );
		return vec[k-1];
    }
	/* 20ms
	int kthSmallest(TreeNode* root, int& k) {
		if (root) {
			int x = kthSmallest(root->left, k);
			return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
		}
		else return 0;
	}
	*/
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
