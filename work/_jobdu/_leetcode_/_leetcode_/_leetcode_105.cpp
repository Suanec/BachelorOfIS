/*
105. Construct Binary Tree from Preorder and Inorder Traversal My Submissions Question
Total Accepted: 58849 Total Submissions: 208485 Difficulty: Medium
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
#include"leetcode.h"
//	//int mid0[]={1,2,3,4,5,6,7,8,9,10,11};//{-1};
//	//int beh0[]={1,3,5,7,6,4,2,9,11,10,8};//{-1};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() <= 0) return NULL;
		return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prel, int preh, int inl, int inh ){
		if(!(inl-inh)) return new TreeNode( inorder[inl] );
		TreeNode* pRes = new TreeNode( preorder[prel] );
		int i = inl;
		while( pRes->val - inorder[i] ) i++;
//		i--;
		int leftCount = i - inl;
		int rightCount = inh - i;
		if( leftCount ) pRes->left = build( preorder, inorder, prel+1, prel+leftCount, inl, inl+leftCount-1);
		if( rightCount ) pRes->right = build( preorder, inorder, prel+leftCount+1, preh, inl+leftCount+1, inh);
		return pRes;
	}
};

/*********************************************************

                         main()

*********************************************************/

//8,2,1,4,3,6,5,7,10,9,11
//int main()
//{
//	TreeNode* Th;
//	Solution s;
//	int pre0[]={8,2,1,4,3,6,5,7,10,9,11};//{-1};
//	int mid0[]={1,2,3,4,5,6,7,8,9,10,11};//{-1};
//	vector<int> mid(mid0, mid0+11);
//	//int i;
//	//for(i = 0; i<11; i++) cout<<mid0[i]<<endl;
//	//= {1,2,3,4,5,6,7,8,9,10,11}
//	vector<int> pre(pre0, pre0+11);
//	Th=s.buildTree(pre,mid);
//	//AOrder(Th);	
//	system("pause");return 0;
//}
