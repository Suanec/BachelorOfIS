/*
121. Best Time to Buy and Sell Stock   My Submissions QuestionEditorial Solution
Total Accepted: 99532 Total Submissions: 275958 Difficulty: Easy
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include"leetcode.h"



class Solution {
public:
	/// 12ms
    int maxProfit(vector<int>& prices) {
		if( prices.size() < 2 ) return 0;
		vector<int> vec(prices.size(),0);
		int buyPrice = prices[0];
		vec[0] = buyPrice * -1;
		for( int i = 1; i < prices.size(); i++ ){
			if( prices[i] < buyPrice ) {
				buyPrice = prices[i];
				vec[i] = buyPrice * -1;
			}
			else{
				vec[i] = prices[i] - buyPrice;
			}
		}
		int maxProfit = 0;
		for( int i = 0; i < vec.size(); i++ ){
			if( vec[i] > maxProfit ) maxProfit = vec[i];
		}
		return maxProfit;
    }
	/// 8ms
	//int maxProfit(vector<int>& prices) {
	//	int maxPro = 0, minPrice = INT_MAX;
	//	for(int i = 0; i < prices.size(); i++) {
	//		minPrice = min(minPrice, prices[i]);
	//		maxPro = max(prices[i] - minPrice, maxPro);
	//	}
	//	return maxPro;
	//}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[2] = {1,2};
//	vector<int> vec(a, a+2);
//	slt.maxProfit(vec);
// 	//system("pause");
//}
