/*
96. Unique Binary Search Trees   My Submissions QuestionEditorial Solution
Total Accepted: 81864 Total Submissions: 218678 Difficulty: Medium
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


思路分析：这题关键在于把握BST的结构特征，从i=0,1,2...逐渐找出递推规律，用count[i]表示有i个节点是BST的数量，那么
i = 0 时 count[i] = 1// 空树
i = 1 时 count[i] = 1//以1为root
i = 2 时 count[i] = count[0]* count[1]//以1为root
                              + count[1]*count[0]//以2为root
i = 3 是 count[i] = count[0]*count[2]//以1为root   都在右子树
                              + count[1]*count[1]//以2为root  左边右边各一个
                              + count[2]*count[0]//以3为root    都在左子树
....
也就是对于 节点1，2，3...i,i+1,...n而言，如果选择i当作root，左边有1，2...i-1,右边有i+1...n。 于是左右子树又划归成了规模较小的已经解决的问题，很容易找到如下递推公式，用DP求解。
count[i] = ∑ count[k] *count [ i-1-k]     0<=k<=i-1
这个就是卡特兰数的一个定义方式。
DP实现，时间复杂度O（n^2），空间复杂度O（n）
*/

#include"leetcode.h"



class Solution {
public:
    int numTrees(int n) {
		int *cnt = new int[n+1];
		cnt[0] = 1;
		cnt[1] = 1;
		cnt[2] = 2;
		cnt[3] = 5;
		for( int i = 4; i <= n; i++ ) {
			cnt[i] = 0;
			for( int j = 0; j < i; j++ ){
				cnt[i] += cnt[j] * cnt[i-j-1];
			}
		}
		int res = cnt[n];
		delete[] cnt;
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.numTrees(10);
// 	//system("pause");
//}
