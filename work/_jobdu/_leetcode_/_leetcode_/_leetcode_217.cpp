/*
217. Contains Duplicate   My Submissions QuestionEditorial Solution
Total Accepted: 87454 Total Submissions: 211720 Difficulty: Easy
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/


#include"leetcode.h"



class Solution {
public:
	/// 101ms
  //  bool containsDuplicate(vector<int>& nums) {
  //      map<int,int> m;
		//auto iter = nums.begin();
		//while( iter != nums.end() ) m[*iter++]++;
		//auto miter = m.begin();
		//while( miter != m.end() ) {
		//	if( miter->second - 1 ) return true;
		//	miter++;
		//}
		//return false;
  //  }
	/// 96ms
	//bool containsDuplicate(vector<int>& nums) {
 //       if(!nums.size()) return false;
 //       map<int,int> m;
	//	auto iter = nums.begin();
	//	while( iter != nums.end() ) m[*iter++]++;
	//	auto miter = m.begin();
	//	while( miter != m.end() ) {
	//		if( miter->second - 1 ) return true;
	//		miter++;
	//	}
	//	return false;
 //   }
	/// 40ms
    bool containsDuplicate(vector<int>& nums) {
		if(nums.size()<2) return false;
		int pre = 0;
		sort(nums.begin(),nums.end());
		auto iter = nums.begin();
		while( iter != nums.end() ){
			pre = *iter;
			iter++;
			if( !(*iter - pre) ) return true;
		}
		return false;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
