/*
347. Top K Frequent Elements   My Submissions QuestionEditorial Solution
Total Accepted: 1611 Total Submissions: 3627 Difficulty: Medium
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include"leetcode.h"



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num = 0; num < nums.size(); num++){
            map[nums[num]]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }

	/// 36ms
	//vector<int> topKFrequent(vector<int>& nums, int k) {
 //       unordered_map<int ,int >um;
 //       int n=nums.size();
 //       vector<int>res;
 //       if(n==0) return res;
 //       for(int i=0;i<n;i++){
 //           um[nums[i]]++;
 //       }
 //       map<int,queue<int> >m;
 //       for(auto it=um.begin();it!=um.end();it++){
 //           m[it->second].push(it->first);
 //       }
 //       auto it=--m.end();
 //       while(k--){
 //           if((it->second).empty()) it--;
 //           res.push_back((it->second).front());
 //           (it->second).pop();
 //       }
 //       return res;
 //   }

//	Solution 1: Using a min heap. O(nlogk)
//
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> counts;
//        priority_queue<int, vector<int>, greater<int>> max_k;
//        for(auto i : nums) ++counts[i];
//        for(auto & i : counts) {
//            max_k.push(i.second);
//            // Size of the min heap is maintained at equal to or below k
//            while(max_k.size() > k) max_k.pop();
//        }
//        vector<int> res;
//        for(auto & i : counts) {
//            if(i.second >= max_k.top()) res.push_back(i.first);
//        }
//        return res;
//    }
//};
//	Soution 2: Bucket sort. O(n)
//
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> counts;
//        for(auto i : nums) ++counts[i];
//
//        vector<vector<int>> buckets(nums.size() + 1);
//        for(auto & k : counts) 
//            buckets[k.second].push_back(k.first);
//        reverse(begin(buckets), end(buckets));
//
//        vector<int> res;
//        for(auto & bucket: buckets) 
//            for(auto i : bucket) {
//                res.push_back(i);
//                if(res.size() == k) return res;
//            }
//
//        return res;
//    }
//};
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	map<int,int>m;
//	m[3]++;
//	int a[] = {1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,1,1,1,1,2,2,2,2,2,5,22,2,2,2,2,2,1,2};
//	vector<int>vec(a,a+38);
//	
//	vec = slt.topKFrequent(vec, 3);
// 	//system("pause");
//}
