/*
238. Product of Array Except Self   My Submissions QuestionEditorial Solution
Total Accepted: 43752 Total Submissions: 102245 Difficulty: Medium
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include"leetcode.h"



class Solution {
public:
	/// O(n) use division 64ms
  //  vector<int> productExceptSelf(vector<int>& nums) {
		//auto iter = nums.begin();
		//int cnt = 0;
		//while(iter != nums.end()) if(! *iter++) cnt++;
		//if( cnt > 1 ){
		//	iter = nums.begin();
		//	while(iter != nums.end()) *iter++ = 0;
		//	return nums;
		//}

  //      long long product = 1, pr0 = 1;
		//if(!(cnt-1)){
		//	iter = nums.begin();
		//	while(iter != nums.end()){
		//		if(*iter) pr0 *= *iter;
		//		product *= *iter++;
		//	}
		//	iter = nums.begin();
		//	while(iter != nums.end()){
		//		if(*iter) *iter = 0;
		//		else *iter = pr0;
		//		iter++;
		//	}
		//	return nums;
		//}
		//iter = nums.begin();
		//while(iter != nums.end()) product *= *iter++;
		//iter = nums.begin();
		//while(iter != nums.end()){
		//	*iter = product / *iter;
		//	iter++;
		//}
		//return nums;
  //  }
	/// O(n) 60ms
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res;
		res.push_back(1);
		long long tem = res[0];
		auto iter = nums.begin(), sentry = nums.end();
		sentry--;
		while(iter != sentry) res.push_back(tem *= *iter++);
		tem = 1;
		for( int i = nums.size()-1; i >= 0; i--){
			res[i] *= tem;
			tem *= nums[i];
		}
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[4] = {1,2,3,4};
//	int t = 3;
//	vector<int> vec(a, a+4);
//	slt.productExceptSelf(vec);
// 	//system("pause");
//}
