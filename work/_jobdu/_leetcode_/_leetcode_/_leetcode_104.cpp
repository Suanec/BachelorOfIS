/*
104. Maximum Depth of Binary Tree
Total Accepted: 134529 Total Submissions: 282709 Difficulty: Easy
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Subscribe to see which companies asked this question
*/

#include<iostream>
using namespace std;
#include"leetcode.h"



class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( !root ) return 0;
		return max(maxDepth(root->left), maxDepth(root->right) ) + 1;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
// 	system("pause");
//}