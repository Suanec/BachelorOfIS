/*
345. Reverse Vowels of a String My Submissions QuestionEditorial Solution
Total Accepted: 16059 Total Submissions: 45475 Difficulty: Easy
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

#include"leetcode.h"



class Solution {
public:
    string reverseVowels(string s) {
		if(!s.length()) return "";
		char *c = new char(s.size());
		char *r = new char(s.length() + 1);
		int i = 0, j = 0;
		for( i = 0; i < s.length(); i++ ){
			char ci = s[i];
			if( ci == '\\' ) continue;
			if( ci == 'a' ||
				ci == 'e' ||
				ci == 'i' ||
				ci == 'o' ||
				ci == 'u' )
				c[j++] = ci;
		}
		c[j--] = 0;
		for( i = 0; i< s.length(); i++ ) {
			char ci = s[i];
			if( ci == '\\' ) continue;
			if( ci  == 'a' ||
				ci  == 'e' ||
				ci  == 'i' ||
				ci  == 'o' ||
				ci  == 'u' ){
					ci = c[j--];
					r[i] = ci;
			}
			else r[i] = ci;
		}
		r[s.length()] = '\0';
		s.clear();
		s.append(r);
		return s;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.reverseVowels("race car");
//	slt.reverseVowels("\"Sirrah! Deliver deified desserts detartrated!\" stressed deified reviled Harris.");
// 	//system("pause");
//}
