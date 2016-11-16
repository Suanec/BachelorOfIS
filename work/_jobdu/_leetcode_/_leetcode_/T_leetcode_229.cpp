/*
Given an integer array of size n, find all elements that appear more than  n/3  times. The algorithm should run in linear time and in O(1) space.
*/


#include"leetcode.h"



class Solution {
public:
	int majorE(vector<int>& nums) {
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
	vector<int> majorityElement(vector<int>& nums) {
        int mst = majorE(nums);
		vector<int> res;
		int cnt = 0;
		for( int i = 0; i< nums.size(); i++ ){
			if( nums[i] - mst ){
				nums[i-cnt] = nums[i];
			}
			else {
				cnt ++;
			}
		}
		if( cnt >= nums.size()/3 ) res.push_back(mst);
		else return res;
		mst = nums[0];
		int tail = nums.size() - cnt;
		cnt = 0;
		for( int i = 0; i < tail; i++){
			if(cnt){
				( nums[i] - mst ) ? cnt-- : cnt++;
			}
			else{
				mst = nums[i];
				cnt++;
			}
		}
		cnt = 0;
		for( int i = 0; i< tail; i++ ){
			if( nums[i] - mst ){
				nums[i-cnt] = nums[i];
			}
			else {
				cnt ++;
			}
		}
		if( cnt >= nums.size()/3 ) res.push_back(mst);
		return res;

    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
