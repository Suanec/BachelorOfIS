/*
145. Binary Tree Postorder Traversal   My Submissions QuestionEditorial Solution
Total Accepted: 95439 Total Submissions: 269925 Difficulty: Hard
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?


*/

#include"leetcode.h"

class Solution {
public:
	/// Recursive solution
	/*
	void postOrder( TreeNode* root, vector<int>& vec ) {
		if( !root ) return ;
		postOrder( root->left, vec );
		postOrder( root->right, vec );
		vec.push_back( root->val );
	}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		postOrder( root, res );
		return res;
    }
	*/
	/// iteratively
	vector<int> postorderTraversal(TreeNode* root) {
        if( !root ) return vector<int>();
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p = root;
		s.push(p);
		set<int> set;
		while(!s.empty()){
			p = s.top();
			s.pop();
			res.insert( res.begin(), p->val );
			if( p->right ) s.push( p->right );
			if( p->left ) s.push( p->left );
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
//	set<int> set;
//	set.insert(2);
//	set.insert(5);
//	vector<int> vec;
//	vec.push_back(2);
//	vec.insert(vec.begin(),3);
//	vector<int>::iterator iter = vec.begin();
//	int t = *iter;
//	vec.insert(vec.begin(),5);
//	vec.insert(vec.begin(),7);
//	t = *iter;
//	//vec.insert(1,6);
//	set.erase(5);
// 	system("pause");
//}
