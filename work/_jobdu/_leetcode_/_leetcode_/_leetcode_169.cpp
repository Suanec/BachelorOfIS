/*
169. Majority Element
Total Accepted: 111542 Total Submissions: 270216 Difficulty: Easy
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/


#include"leetcode.h"



class Solution {
public:
	/// 20ms
    int majorityElement(vector<int>& nums) {
        int sentry = nums[0];
		int cnt = 1;
		auto iter = nums.begin();
		iter++;
		while( iter != nums.end() ){
			if(cnt){
				( *iter - sentry ) ? cnt-- : cnt++;
			}
			else {
				sentry = *iter;
				cnt++;
			}
			iter++;
		}
		return sentry;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[2] = {2,3};
//	vector<int>vec(a,a+2);
//	auto iter = vec.begin();
//	auto i = iter+1;
//	slt.majorityElement(vec);
// 	//system("pause");
//}
