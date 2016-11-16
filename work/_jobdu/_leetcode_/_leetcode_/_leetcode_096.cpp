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


˼·����������ؼ����ڰ���BST�Ľṹ��������i=0,1,2...���ҳ����ƹ��ɣ���count[i]��ʾ��i���ڵ���BST����������ô
i = 0 ʱ count[i] = 1// ����
i = 1 ʱ count[i] = 1//��1Ϊroot
i = 2 ʱ count[i] = count[0]* count[1]//��1Ϊroot
                              + count[1]*count[0]//��2Ϊroot
i = 3 �� count[i] = count[0]*count[2]//��1Ϊroot   ����������
                              + count[1]*count[1]//��2Ϊroot  ����ұ߸�һ��
                              + count[2]*count[0]//��3Ϊroot    ����������
....
Ҳ���Ƕ��� �ڵ�1��2��3...i,i+1,...n���ԣ����ѡ��i����root�������1��2...i-1,�ұ���i+1...n�� �������������ֻ�����˹�ģ��С���Ѿ���������⣬�������ҵ����µ��ƹ�ʽ����DP��⡣
count[i] = �� count[k] *count [ i-1-k]     0<=k<=i-1
������ǿ���������һ�����巽ʽ��
DPʵ�֣�ʱ�临�Ӷ�O��n^2�����ռ临�Ӷ�O��n��
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
