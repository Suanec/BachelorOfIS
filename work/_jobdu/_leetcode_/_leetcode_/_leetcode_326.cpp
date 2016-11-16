/*
326. Power of Three   My Submissions QuestionEditorial Solution
Total Accepted: 40791 Total Submissions: 110615 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

#include"leetcode.h"



class Solution {
public:
    bool isPowerOfThree(int n) {
		int a[] = {3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
		for( int i = 0; i< 19; i++ ) if( n == a[i] ) return true;
		return false;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.isPowerOfThree(1);
// 	//system("pause");
//}
