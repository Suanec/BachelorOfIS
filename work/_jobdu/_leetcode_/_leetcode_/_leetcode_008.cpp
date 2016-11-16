/*
8. String to Integer (atoi)   My Submissions QuestionEditorial Solution
Total Accepted: 100228 Total Submissions: 743043 Difficulty: Easy
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include"leetcode.h"



class Solution {
public:
	/// long long to prevent out of the range 8ms
//    int myAtoi(string str) {
//		int size = str.length();
//		if( !size ) return 0;
//		long long res = 0;
//		int i = 0;
//		while( str[i] == ' ' ) i++;
//		int nonSpace = i;
//
//		if( str[i] == '+' || str[i] == '-' ) i++;
//		for( i ; i < size; i++ ){
//			char c = str[i];
//			if( c < '0' || c > '9' ){
//				if(res){
//					if( str[nonSpace] == '-' ) return res * -1;
//					else return res;
//				}
//				else return 0;
//			}
//			else {
//				int tem = c - '0';
//				int target = res * 10 + tem;
//				if( res - (target-tem)/10 ) {
//					if( str[nonSpace] == '-' ) return INT_MIN;
//					else return INT_MAX;
//				}
//				res *= 10;
//				res += (c - '0');
//			}
//		}
//		if( str[nonSpace] == '-' ) res *= -1;
//		if( res > INT_MAX ) return INT_MAX;
//		if( res < INT_MIN ) return INT_MIN;
//// 		if(res && (res == res * -1) && str[nonSpace] != '-' ) return INT_MAX;
//		return res;
//    }
	/// 8ms
    int myAtoi(string str) {
		int size = str.length();
		if( !size ) return 0;
		int res = 0, i = 0;
		while( str[i] == ' ' ) i++;
		int nonSpace = i;

		if( str[i] == '+' || str[i] == '-' ) i++;
		for( i ; i < size; i++ ){
			char c = str[i];
			if( c < '0' || c > '9' ){
				if(res){
					if( str[nonSpace] == '-' ) return res * -1;
					else return res;
				}
				else return 0;
			}
			else {
				int tem = c - '0';
				int target = res * 10 + tem;
				if( res - (target-tem)/10 ) {
					if( str[nonSpace] == '-' ) return INT_MIN;
					else return INT_MAX;
				}
				res *= 10;
				res += (c - '0');
			}
		}
		if(res == INT_MIN+1) return INT_MIN;
		if( str[nonSpace] == '-' ) res *= -1;
		if(res && (res == res * -1) && str[nonSpace] != '-' ) return INT_MAX;
		return res;
    }

};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.myAtoi("     +004500a");
//	slt.myAtoi("+");
//	slt.myAtoi("1a");
//	slt.myAtoi("2147483648");/// excepted 2147483647
//	slt.myAtoi("2147483647");/// excepted 2147483647
//	slt.myAtoi("-2147483649");/// excepted -2147483648
//	slt.myAtoi("      -11919730356x");/// excepted -2147483648
// 	//system("pause");
//}
