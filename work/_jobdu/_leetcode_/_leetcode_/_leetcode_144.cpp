/*
144. Binary Tree Preorder Traversal   My Submissions QuestionEditorial Solution
Total Accepted: 117965 Total Submissions: 296846 Difficulty: Medium
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include"leetcode.h"

class Solution {
public:
/// Recursive solution
	/*
	void preOrder( TreeNode* root, vector<int>& vec ){
		if( !root ) return ;
		if( !root->left && ! root->right ) vec.push_back(root->val);
		else{
			vec.push_back( root->val );
			preOrder( root->left, vec );
			preOrder( root->right, vec );
		}
	}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		preOrder( root, res );
		return res;
    }
	*/
/// iteratively
/// other's
/*
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		if (root==NULL) {
			return vector<int>();
		}
		vector<int> result;
		stack<TreeNode *> treeStack;
		treeStack.push(root);
		while (!treeStack.empty()) {
			TreeNode *temp = treeStack.top();
			result.push_back(temp->val);
			treeStack.pop();
			if (temp->right!=NULL) {
				treeStack.push(temp->right);
			}
			if (temp->left!=NULL) {
				treeStack.push(temp->left);
			}
		}
		return result;
	}
};
*/
    vector<int> preorderTraversal(TreeNode* root) {
		if( !root ) return vector<int>();
		stack<TreeNode*> s;
		vector<int> res;
		s.push(root);
		while(!s.empty()){
			TreeNode* p = s.top();
			s.pop();
			res.push_back( p->val );
			if( p->right ) s.push(p->right);
			if( p->left ) s.push(p->left);
		}
		return res;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	TreeNode a(2);
//	TreeNode r(1);
//	r.left = &a;
//	slt.preorderTraversal( &r );
// 	system("pause");
//}
