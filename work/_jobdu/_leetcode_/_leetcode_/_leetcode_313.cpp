/*
313. Super Ugly Number   My Submissions QuestionEditorial Solution
Total Accepted: 12394 Total Submissions: 36607 Difficulty: Medium
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.
*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n+1);
		int pSize = primes.size();
		vector<int> k(pSize,1);
		//for( int i = 0; i< pSize; i++) k[i] = 1;
		int cnt = 1;
		res[1] = 1;
		while( cnt < n ){
			cnt ++;
			int idx = 0;
			int tem = INT_MAX;
			for( int i = 0; i < pSize; i++ ){
				if( tem > res[k[i]] * primes[i] ) {
					tem = res[k[i]] * primes[i];
					idx = i;
				}
			}
			if( tem > res[cnt-1] ){
				res[cnt] = tem;
			}
			else cnt--;
			k[idx] ++;
		}
		return res[cnt];
    }

	//int nthSuperUglyNumber(int n, vector<int>& primes) {
 //       vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
 //       ugly[0]=1;
 //       for(int i=1; i<n; i++){
 //           for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
 //           for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
 //       }
 //       return ugly[n-1];
	//}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	vector<int> vec;
//	vec.push_back(2);
//	vec.push_back(7);
//	vec.push_back(13);
//	vec.push_back(19);
//	s.nthSuperUglyNumber(12,vec);
// 	system("pause");
//}
