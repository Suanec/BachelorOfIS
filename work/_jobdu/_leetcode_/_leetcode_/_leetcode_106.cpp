/**
106. Construct Binary Tree from Inorder and Postorder Traversal My Submissions Question
Total Accepted: 51501 Total Submissions: 179713 Difficulty: Medium
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//		return CreBiTr( inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
//    }
//	TreeNode* CreBiTr(vector<int>& mid,vector<int>& beh,int low1,int high1,int low2,int high2)
//	{
//		if((high2-low2)!=(high1-low1))return NULL;
//		TreeNode* p=new TreeNode(0);
//		if(!(high2-low2))
//		{
//		//	TreeNode* p=new TreeNode;
//			p->val=beh[high2];p->left=p->right=NULL;
//		}//if
//		else
//		{
//		//	TreeNode* p=new TreeNode;
//			p->val=beh[high2];
//			int i=high1;
//			while(p->val!=mid[i])--i;
//			p->left=CreBiTr(mid,beh,low1,i-1,low2,high2-high1+i-1);
//			p->right=CreBiTr(mid,beh,i+1,high1,high2-high1+i,high2-1);
//		}//else
//		return p;
//	}//CreBiTr();
//
//};

/// Runtime error 重写  90% beaten ///

class Solution {
public:
	TreeNode* build(vector<int>& in, vector<int>& post, int inl, int inh, int postl, int posth){
		if(!(inl-inh)){
			return new TreeNode(in[inl]);
		}
		TreeNode* pRes = new TreeNode(post[posth]);
		int i = inh;
		while( in[i--] - pRes->val );
		i++;
		if(i - inl) pRes->left = build( in, post, inl, i-1, postl, postl+i-inl-1);//, postl+i-inl+inh-i);i-inl
		if(postl+i-inl-posth) pRes->right = build( in, post, i+1, inh, postl+i-inl, posth-1 );
		return pRes;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.size() <= 0) return NULL;
		return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};

/// 利用左右子树节点数目计算，AC ///
//class Solution {
//public:
//    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
//        int size = inorder.size();
//        if(size <= 0){
//            return nullptr;
//        }//if
//        return InPostBuildTree(inorder,postorder,0,size-1,size);
//    }
//private:
//    TreeNode* InPostBuildTree(vector<int> &inorder,vector<int> &postorder,int inIndex,int postIndex,int size){
//        if(size <= 0){
//            return nullptr;
//        }//if
//        // 根节点
//        TreeNode* root = new TreeNode(postorder[postIndex]);
//        // 寻找postorder[postIndex]在中序序列中的下标
//        int index = 0;
//        for(int i = 0;i < size;++i){
//            if(postorder[postIndex] == inorder[inIndex+i]){
//                index = inIndex+i;
//                break;
//            }//if
//        }//for
//        int leftSize = index - inIndex;
//        int rightSize = size - leftSize - 1;
//        root->left = InPostBuildTree(inorder,postorder,inIndex,postIndex-1-rightSize,leftSize);
//        root->right = InPostBuildTree(inorder,postorder,index+1,postIndex-1,rightSize);
//        return root;
//    }
//};
/*********************************************************

                         main()

*********************************************************/


//int main()
//{
//	TreeNode* Th;
//	Solution s;
//	//int mid0[]={1,2,3,4,5,6,7,8,9,10,11};//{-1};
//	//int beh0[]={1,3,5,7,6,4,2,9,11,10,8};//{-1};
//	int mid0[]={1,2};//{-1};
//	int beh0[]={2,1};//{-1};
//	vector<int> mid(mid0, mid0+2);
//	int i;
//	//for(i = 0; i<11; i++) cout<<mid0[i]<<endl;
//	//= {1,2,3,4,5,6,7,8,9,10,11}
//	vector<int> beh(beh0, beh0+2);
//	Th=s.buildTree(mid,beh);
//	//AOrder(Th);	
//	system("pause");return 0;
//}
