/*
95. Unique Binary Search Trees II   My Submissions QuestionEditorial Solution
Total Accepted: 54340 Total Submissions: 187592 Difficulty: Medium
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   similar to 096
*/

#include"leetcode.h"



class Solution {
public:
  //  vector<TreeNode*> generateTrees(int n) {
  //      vector<vector<TreeNode*>> temp;
		//int i = n;
		//while((i--) +1) temp.push_back(vector<TreeNode*>());
  //      temp[0].push_back(NULL);
		//temp[1].push_back(new TreeNode(1));
  //      vector<TreeNode*> res = temp[n];
		//return res;
	//  }
	vector<TreeNode*> generateTrees(int n) {
        if( !n ) return vector<TreeNode*>();
		if( !(n-1) ) {
			vector<TreeNode*> res;
			res.push_back(new TreeNode(1));
			return res;
		}
		vector<vector<TreeNode*>> temp;
		int i = n;
		while( i-- ) temp.push_back(vector<TreeNode*>());
		temp.push_back(vector<TreeNode*>());
        temp[0].push_back(NULL);
		temp[1].push_back(NULL);
// 		while((i--) +1) 
        vector<TreeNode*> res = temp[1];
		return res;

    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.generateTrees(0);
// 	//system("pause");
//}
