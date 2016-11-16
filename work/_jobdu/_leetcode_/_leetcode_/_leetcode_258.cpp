/*
258. Add Digits 
Total Accepted: 83618 Total Submissions: 173121 Difficulty: Easy
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods? Show More Hint 

*/
#include<iostream>
using namespace std;

//class Solution {
//public:
//    int addDigits(int num) {
//		int sum = 0;
//		while(!( num<10 && sum < 10 )){
//
//			while(num/10 > 0) {
//				sum += num % 10;
//				num /= 10;
//			}
//			num += sum;
//			sum = 0;
//
//		}
//		return num;
//	}
//};
//====================================================
//class Solution {
//public:
//    int addDigits( int num ){
//		return num >= 10 ? (num % 9 == 0 ? 9 : num % 9 ) : num;
//	}
//};
//====================================================
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	s.addDigits(19);
// 	system("pause");
//}