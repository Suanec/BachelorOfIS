/*
191. Number of 1 Bits   My Submissions QuestionEditorial Solution
Total Accepted: 89457 Total Submissions: 238107 Difficulty: Easy
Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3
*/

#include"leetcode.h"



class Solution {
public:
	/// 4ms
    int hammingWeight(uint32_t n) {
        int cnt = 0, i = 32;
		while( i-- && n ){
			cnt += n&1;
			n>>=1;
		}
		return cnt;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.hammingWeight(1);
// 	//system("pause");
//}
