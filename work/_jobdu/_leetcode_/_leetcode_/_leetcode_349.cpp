/*
349. Intersection of Two Arrays My Submissions QuestionEditorial Solution
Total Accepted: 7637 Total Submissions: 16772 Difficulty: Easy
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

#include"leetcode.h"



class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if( ! nums1.size() || ! nums2.size() ) return vector<int>();
		vector<int> res;
		set<int> set,setRes;
		vector<int> tem;
		auto iterEnd = nums2.end(), iter2 = nums2.begin();
		if( nums1.size() > nums2.size() ) {
			tem.assign(nums2.begin(),nums2.end());
			iterEnd = nums1.end();
			iter2 = nums1.begin();
		}
		else{
			tem.assign(nums1.begin(), nums1.end());
			iterEnd = nums2.end();
			iter2 = nums2.begin();
		}
		auto iter = tem.begin();
		while( iter != tem.end() ) set.insert(*iter++);
		while( iter2 != iterEnd ){
			auto iterSet = set.find(*iter2);
			if( iterSet != set.end() ) setRes.insert( * iter2 );
			iter2 ++;
		}
		auto iter1 = setRes.begin();
		while( iter1 != setRes.end() ) res.push_back( *iter1++);
		return res;
    }

};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[1] = {1};
//	vector<int> arr( a, a+1);
//	vector<int> brr( a, a+1);
//	set<int> set;
//	set.insert(9);
//	set.insert(9);
//	set.insert(*arr.begin());
//	slt.intersection(arr,brr);
// 	//system("pause");
//}
