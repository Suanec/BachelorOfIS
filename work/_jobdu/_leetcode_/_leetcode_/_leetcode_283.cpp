/*
283. Move Zeroes   My Submissions QuestionEditorial Solution
Total Accepted: 78184 Total Submissions: 176905 Difficulty: Easy
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include"leetcode.h"



class Solution {
public:
	/// 26ms
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
		int size = nums.size();
		for( int i = 0; i < size; i++ ){
			if( nums[i] ) {
				if(cnt) nums[i-cnt] = nums[i];
			}
			else cnt++;
		}
		while(cnt--) nums[size-cnt-1] = 0;
    }
	/// effective a little 20ms
	//void moveZeroes(vector<int>& nums) {
	//	int j = 0;
	//	for (int i = 0; i < nums.size(); i++) {
	//		if (nums[i] != 0) {
	//			nums[j++] = nums[i];
	//		}
	//	}
	//	for (;j < nums.size(); j++) {
	//		nums[j] = 0;
	//	}
	//}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[] = {0, 1, 0, 3, 12};
//	vector<int> vec(a,a+5);
//	slt.moveZeroes(vec);
// 	//system("pause");
//}
