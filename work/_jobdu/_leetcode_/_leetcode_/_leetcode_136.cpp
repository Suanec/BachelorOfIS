/*
136. Single Number   My Submissions QuestionEditorial Solution
Total Accepted: 126010 Total Submissions: 253539 Difficulty: Medium
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include"leetcode.h"



class Solution {
public:
    int singleNumber(vector<int>& nums) {
		for( int i = 1; i < nums.size(); i++ ){
			nums[0] ^= nums[i];
		}
		return nums[0];
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a = 1;
//		a ^= 1;
//		a = 3;
//		a ^= 1;
// 	//system("pause");
//}
