/*
322. Coin Change My Submissions QuestionEditorial Solution
Total Accepted: 16789 Total Submissions: 68056 Difficulty: Medium
You are given coins of different denominations(币值，面值） and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//		//std::sort(coins.begin(), coins.end());
//		return coinChan( coins, coins.size()-1, amount );
//    }
//	int coinChan( vector<int>& coins, int n, int amount ) {
//		if( n < 0 || amount < 0 ) return -1;
//		if( amount == 0 ) return 0;
//		if( (amount % coins[n]) == 0 ) return amount/coins[n] ;
//		if( (amount < coins[n]) ) return coinChan(coins, n-1, amount);
//		int ret_sum = 0;
//		int ret, times, i;
//		i = n;
//		while( i >= 0 ) {
//			if( (times = amount / coins[i]) > 0 ) {
//				for( int j = times; j >= 0 ; j--){
//					ret = coinChan( coins, n-(n-i)-1, amount - coins[i] * j );
//					if(ret<0) ret = -1;
//					else if(ret_sum){
//						if( ret_sum > ret + j && ret + j != 0) ret_sum = ret + j;
//					}
//					else ret_sum = ret + j;
//				}
//			}
//			i--;
//		}
//		return ret_sum;
//
//	}
//};
/*
动态规划
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i=0; i<amount; i++) {
            for(int j=0; j<(int)coins.size(); j++) {
                if(dp[i] != INT_MAX) {
                    if(i+coins[j]<=amount) dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
                }
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};

============================================================
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> res(amount + 1, INT_MAX);
        for(int i = 0; i < coins.size(); i++)
            if(coins[i] < amount + 1) res[coins[i]] = 1;
        for(int i = 1; i <= amount; i++)
            for(int j = 0; j < coins.size(); j++)
                if(i - coins[j] > 0 && res[i - coins[j]] != INT_MAX) 
                    res[i] = min(res[i],res[i - coins[j]] + 1); 
        return res[amount] == INT_MAX ? -1 : res[amount];
    }
};
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		//std::sort(coins.begin(), coins.end());
		//总金额为0，直接返回0
		if(!amount) return 0;
		//总金额小于所给面值最小值，直接返回-1；
		if(coins[0]>amount) return -1;
		//总金额小于0；
		if(amount<0)return -1;
		//总金额等于各面值
		for(int i = 0; i < coins.size(); i++) if(!(coins[0]-amount)) return 1;
		vector<int> dp;
		dp.assign( amount + 1, INT_MAX );
		dp[0] = 0;
		for( int i = 0 ; i <= amount; i++ ){
			for( int j = 0; j < coins.size(); j++){
				if( dp[i] - INT_MAX && i + coins[j] <= amount )
					dp[i+coins[j]] = ::min( dp[i+coins[j]], dp[i]+1 );			
			}
		}
		return dp[amount] - INT_MAX ? dp[amount] : -1 ;
    }
};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	int coin[]={83,186,408,419};//{-1};
//	vector<int> coins(coin, coin+4);
//	vector<int> coins2;
//	coins2.assign(1,1);
//	//coins2.assign(10,9);
//	int a = INT_MAX;
//	//s.coinChange(coins2,1);
//	vector<int> tem(coins2);
//	//int i;
//	//for(i = 0; i<11; i++) cout<<mid0[i]<<endl;
//	//= {1,2,3,4,5,6,7,8,9,10,11}
//	s.coinChange(coins2, 2);
//
// 	system("pause");
//}