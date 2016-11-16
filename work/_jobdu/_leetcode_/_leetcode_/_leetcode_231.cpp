/*
231. Power of Two   My Submissions QuestionEditorial Solution
Total Accepted: 71934 Total Submissions: 196082 Difficulty: Easy
Given an integer, write a function to determine if it is a power of two.
*/

#include"leetcode.h"



class Solution {
public:
	bool isPowerOfTwo(int n) {
        if(n<=0) return false;
		int bit = n & ~(n-1);
		while( bit ){
			bit>>= 1;
			n>>=1;
		}
		return n ? false : true;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
