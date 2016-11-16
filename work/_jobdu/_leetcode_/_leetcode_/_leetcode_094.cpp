/*
94. Binary Tree Inorder Traversal   My Submissions QuestionEditorial Solution
Total Accepted: 120989 Total Submissions: 305884 Difficulty: Medium
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

#include"leetcode.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
		inorder( root, vec );
		return vec;
    }
	void inorder( TreeNode* root, vector<int> & vec ) {
		if( !root ) return ;
		if( !root->left && ! root->right ) vec.push_back(root->val);
		else{
			inorder( root->left, vec );
			vec.push_back( root->val );
			inorder( root->right, vec );
		}
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
