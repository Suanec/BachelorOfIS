/*
263. Ugly Number   My Submissions QuestionEditorial Solution
Total Accepted: 52743 Total Submissions: 144470 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/
#include"leetcode.h"
#include<iostream>
using namespace std;
class Solution {
public:
  //  bool isUgly(int num) {
  //      if(num<0) return false;
		//bool *arr = new bool(num+1);
		//arr[0] = false;
		//for(int i = 1; i < 7; i++) arr[i] = true;
		//for(int i = 7; i <= num; i++){
		//	if(!(i%2)) {
		//		arr[i] = arr[i/2];
		//		continue;
		//	}
		//	if(!(i%3)) {
		//		arr[i] = arr[i/3];
		//		continue;
		//	}
		//	if(!(i%5)) {
		//		arr[i] = arr[i/5];
		//		continue;
		//	}
		//	arr[i] = false;
		//}
		//return arr[num];
  //  }
	bool isUgly(int num) {
		if(num<=0) return false;
		while(num && !(num % 2)) num /= 2;
		while(num && !(num % 3)) num /= 3;
		while(num && !(num % 5)) num /= 5;
		return num == 1;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	//int res = s.getValue(a1,7);
//	//cout<<res<<endl;
//
//	bool a = s.isUgly(2);
// 	//system("pause");
//}