/*
7. Reverse Integer   My Submissions QuestionEditorial Solution
Total Accepted: 137375 Total Submissions: 581589 Difficulty: Easy
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include"leetcode.h"



class Solution {
public:
    int reverse(int x) {
        int res = 0;
		if( x == -2147483648 ) return 0;
		int c = abs(x);
		while( c/10>0 ){
			res *= 10;
			res += c % 10;
			c /= 10;
		}
		if( res * 10 / 10 - res ) return 0;
		res *= 10;
		res += c;
		if( x < 0 ) res *= -1;
		return res;
    }
    //int reverse(int x) {
    //    long long res = 0;
    //    while(x) {
    //        res = res*10 + x%10;
    //        x /= 10;
    //    }
    //    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    //}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a = slt.reverse(1534236469);
//	a = slt.reverse(-2147483648);
// 	//system("pause");
//}
