/*
344. Reverse String   My Submissions QuestionEditorial Solution
Total Accepted: 10786 Total Submissions: 18463 Difficulty: Easy
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include"leetcode.h"



class Solution {
public:
	/// self
  //  string reverseString(string s) {
		//string res = "";
		//char carr[2] = { '\0', '\0' };
		//for( int i = s.length(); i >= 0 ; i-- ){
		//	carr[0] = s[i];
		//	string tem(carr);
		//	res.append(tem);
		//}
		//return res;
  //  }
	/// others
	string reverseString(string s) {
		auto h = s.begin();
		auto t = s.end() - 1;
		while (h < t) { swap(*h++, *t--); }
		return s;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.reverseString("hello");
// 	//system("pause");
//}
