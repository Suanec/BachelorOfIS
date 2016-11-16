/*
242. Valid Anagram   My Submissions QuestionEditorial Solution
Total Accepted: 78983 Total Submissions: 188958 Difficulty: Easy
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

#include"leetcode.h"



class Solution {
public:
	/// 64ms
  //  bool isAnagram(string s, string t) {
		//int ssize = s.length();
		//int tsize = t.length();
		//if( !ssize && !tsize ) return true;
		//map<char,int> sm,tm;
		//int i = 0;
		//int sentry = ssize > tsize ? tsize : ssize;
		//while( i < sentry ) {
		//	sm[s[i]]++;
		//	tm[t[i]]++;
		//	i++;
		//}
		//if(ssize > tsize) while( i < ssize ) sm[s[i++]]++;
		//else while( i < tsize ) tm[t[i++]]++;
		//if( sm.size() - tm.size() ) return false;
		//auto iter = sm.begin();
		//while( iter != sm.end() ){
		//	auto temIter = tm.find( iter->first );
		//	if( temIter == tm.end() ) return false;
		//	int tem = temIter->second;
		//	if( tem - iter->second ) return false;
		//	iter++;
		//}
		//return true;
  //  }
	/// 12ms
    bool isAnagram(string s, string t) {
		int ssize = s.length();
		int tsize = t.length();
		if( !ssize && !tsize ) return true;
		else if( ssize - tsize ) return false;
		int shash[26] = {0};
		int thash[26] = {0};
		int i = 0;
		while( i < ssize ) {
			shash[ s[i]-'a' ]++;
			thash[ t[i]-'a' ]++;
			i++;
		}
		i = -1;
		while ( ++i < 26 ) if( shash[i] - thash[i] ) return false;
		return true;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.isAnagram("anagram","nagaram");
//	slt.isAnagram("cat","rcat");
//	slt.isAnagram("a","ab");
// 	//system("pause");
//}
