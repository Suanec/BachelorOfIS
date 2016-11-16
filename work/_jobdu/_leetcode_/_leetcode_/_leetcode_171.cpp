/*
171. Excel Sheet Column Number   My Submissions QuestionEditorial Solution
Total Accepted: 77806 Total Submissions: 186599 Difficulty: Easy
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/


#include"leetcode.h"



class Solution {
public:
    int titleToNumber(string s) {
		if(!s.length()) return 0;
        int res = 0;
		int i = 0;
		char c = 'A';
		while( i < s.length() ){
			c = s[i];
			res *= 26;
			res += (c - 'A')+1;
			i++;
		}
		return res;
    }

};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.titleToNumber("B");
//	slt.titleToNumber("AB");
// 	//system("pause");
//}
