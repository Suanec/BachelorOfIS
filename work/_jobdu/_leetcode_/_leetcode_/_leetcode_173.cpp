/*
173. Binary Search Tree Iterator   My Submissions QuestionEditorial Solution
Total Accepted: 46544 Total Submissions: 135153 Difficulty: Medium
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

#include"leetcode.h"

/// O(n) 版本，n为树中所有元素数量。
//class BSTIterator {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> vec;
//		inorder( root, vec );
//		return vec;
//    }
//	void inorder( TreeNode* root, vector<int> & vec ) {
//		if( !root ) return ;
//		if( !root->left && ! root->right ) vec.push_back(root->val);
//		else{
//			inorder( root->left, vec );
//			vec.push_back( root->val );
//			inorder( root->right, vec );
//		}
//	}
//    BSTIterator(TreeNode *root) {
//		vec = inorderTraversal( root );
//		idx = 0;
//		len = vec.size();
//    }
//
//    /** @return whether we have a next smallest number */
//    bool hasNext() {
//        return idx < len;
//    }
//
//    /** @return the next smallest number */
//    int next() {
//        return vec[idx++];
//    }
//private:
//	int idx,len;
//	vector<int> vec;
//};
/// O(h) 版本
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	TreeNode a(2);
//	TreeNode r(1);
//	r.left = &a;
//	BSTIterator iter(&r);
//	iter.next();
// 	system("pause");
//}
