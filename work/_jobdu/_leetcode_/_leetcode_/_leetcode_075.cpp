/*
75. Sort Colors   My Submissions QuestionEditorial Solution
Total Accepted: 96110 Total Submissions: 277257 Difficulty: Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.
*/

#include"leetcode.h"



class Solution {
public:
	void sortColors(vector<int>& nums) {
		int cnt = nums.size();
		int rcnt = 0;/// 0
		int wcnt = 0;/// 1
		int bcnt = 0;/// 2
		int i = 0;
		for( i = 0; i < cnt; i++ ){
			if( !nums[i] ) rcnt ++;
			else if( !(nums[i]-1) ) wcnt ++;
			else if( !(nums[i]-2) ) bcnt ++;
		}
		if( cnt-rcnt-wcnt-bcnt ) return;
		i = 0;
		while( i < cnt ){
			if(rcnt){
				nums[i++] = 0;
				rcnt--;
				continue;
			}
			if(wcnt){
				nums[i++] = 1;
				wcnt--;
				continue;
			}
			if(bcnt){
				nums[i++] = 2;
				bcnt--;
				continue;
			}
		}
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.sortColors(nums);
// 	//system("pause");
//}
