/*
205. Isomorphic Strings   My Submissions QuestionEditorial Solution
Total Accepted: 54030 Total Submissions: 183483 Difficulty: Easy
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

#include"leetcode.h"

class Solution {
public:
	//bool isIsomorphic(string s, string t) {
	//	char s_t[128], t_s[128];
	//	memset(s_t, 0, 128);
	//	memset(t_s, 0, 128);
	//	int size = s.size();
	//	for(int i = 0; i < size; ++i){
	//		if( s_t[ s[i] ] != 0 && s_t[ s[i] ] != t[i] ) return false;
	//		if( t_s[ t[i] ] != 0 && t_s[ t[i] ] != s[i] ) return false;
	//		s_t[ s[i] ] = t[i];
	//		t_s[ t[i] ] = s[i];
	//	}
	//	return true;
	//}
	bool isIsomorphic(string s, string t) {
		char a[128] = {'\0'},b[128] = {'\0'};
		int size = s.size();
		for( int i = 0; i < size; i++){
			if( a[t[i]] && (a[t[i]] - s[i]) ) return false;
			if( b[s[i]] && (b[s[i]] - t[i]) ) return false;
			a[t[i]] = s[i];
			b[s[i]] = t[i];
		}
		return true;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	vector<int> vec;
//	vec.push_back(2);
//	vec.push_back(7);
//	vec.push_back(13);
//	vec.push_back(19);
//	int a[128] = {0};
//	for(int i = 0; i< 128; i++) a[i] = i;
//	string s = "aa";
//	int tem = a[s[1]];
//	string t = "ab";
//	slt.isIsomorphic(s,t);
//
//	//s.nthSuperUglyNumber(12,vec);
// 	//system("pause");
//}
