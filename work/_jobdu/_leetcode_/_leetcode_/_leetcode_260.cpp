/*
260. Single Number III   My Submissions QuestionEditorial Solution
Total Accepted: 32937 Total Submissions: 75215 Difficulty: Medium
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include"leetcode.h"



class Solution {
public:
	/// 20ms
	vector<int> singleNumber(vector<int>& nums) {
        int res0 = 0, res1 = 0;
		vector<int> ret,zerovec,onevec;
		auto iter = nums.begin();
		while(iter != nums.end()) res0 ^= *iter++;
		res1 = res0 & ~(res0-1);
		iter = nums.begin();
		while(iter != nums.end()){
			if( res1 & *iter ) onevec.push_back(*iter++);
			else zerovec.push_back(*iter++);
		}
		res0 = 0;
		res1 = 0;
		iter = zerovec.begin();
		while(iter != zerovec.end()) res0 ^= *iter++;
		iter = onevec.begin();
		while(iter != onevec.end()) res1 ^= *iter++;
		ret.push_back(res0);
		ret.push_back(res1);
		return ret;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[] = {0,0,1,2};
//	vector<int> vec(a,a+4);
//	slt.singleNumber(vec);
// 	//system("pause");
//}
