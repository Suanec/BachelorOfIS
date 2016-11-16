/*
1. Two Sum   My Submissions QuestionEditorial Solution
Total Accepted: 221662 Total Submissions: 964197 Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

#include"leetcode.h"



class Solution {
public:
	/// 不考虑不存在结果情况，不考虑多个结果情况，不考虑重复元素情况。
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> num(nums);
		::sort(num.begin(),num.end());
		vector<int> res;
		int i = 0, j = nums.size()-1;
		while( i < j ){
			if( num[i] + num[j] < target ) i++;
			if( num[i] + num[j] > target ) j--;
			if( !(num[i] + num[j] - target) ) {
				for( int k = 0; k < nums.size(); k++ ){
					if( nums[k] == num[i] || nums[k] == num[j] ) res.push_back( k );
				}
				return res;
			}
		}
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	vector<int> nums;
//	nums.push_back(3);
//	nums.push_back(2);
//	nums.push_back(4);
//	slt.twoSum(nums,2);
// 	//system("pause");
//}
