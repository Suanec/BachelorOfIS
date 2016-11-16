/*
31. Next Permutation   My Submissions QuestionEditorial Solution
Total Accepted: 65263 Total Submissions: 245820 Difficulty: Medium
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/

#include"leetcode.h"



class Solution {
public:
	/// 12ms
  //  void nextPermutation(vector<int>& nums) {
		//if(nums.size()<2) return;
		//int i = nums.size()-1, j = nums.size()-1, k = nums.size()-1;
		//while( k && nums[k] <= nums[k-1] ) k--;
		//i = k-1;
		//if( !k ) {
		//	sort(nums.begin(), nums.end());
		//	return;
		//}
		//while( j > k ){
		//	if( nums[i] >= nums[j] ) j--;
		//	else break;
		//}
		//nums[i] += nums[j];
		//nums[j] = nums[i] - nums[j];
		//nums[i] = nums[i] - nums[j];
		//sort(nums.begin()+k,nums.end());
  //  }
	/// 12ms a few speed up.
	void swap( int& x , int & y ){
		x += y;
		y = x - y;
		x = x - y;
	}
	void reverseVector( vector<int>& nums, int s, int t ){
		while( s < t ){
			swap(nums[s],nums[t]);
			s++;
			t--;
		}
	}
	//reverse(vec.begin(),vec.end());
	//	for (; _First != _Last && _First != --_Last; ++_First)
	//	_STD iter_swap(_First, _Last);

    void nextPermutation(vector<int>& nums) {
		if(nums.size()<2) return;
		int i = nums.size()-1, j = nums.size()-1, k = nums.size()-1;
		while( k && nums[k] <= nums[k-1] ) k--;
		i = k-1;
		if( !k ) {
			reverseVector(nums,0,nums.size()-1);
			return;
		}
		while( j > k ){
			if( nums[i] >= nums[j] ) j--;
			else break;
		}
		swap(nums[i],nums[j]);
		reverseVector(nums,k,nums.size()-1);
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[3] = {1,2,3};
//	int b[3] = {3,2,1};
//	int c[3] = {1,1,5};
//	vector<int>vec(a,a+3);
//	slt.nextPermutation(vector<int>(a,a+3));
//	slt.nextPermutation(vector<int>(b,b+3));
//	slt.nextPermutation(vector<int>(c,c+3));
// 	//system("pause");
//}
