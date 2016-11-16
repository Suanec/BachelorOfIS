/*
290. Word Pattern   My Submissions QuestionEditorial Solution
Total Accepted: 33544 Total Submissions: 115886 Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

#include"leetcode.h"

class Solution {
public:
	/// 2ms
	/// 利用一个哈希表，随后遍历哈希表，保证每个字符串对应一个位置。
	bool wordPattern(string pattern, string str) {
		int size = pattern.size();
		vector<string> data;
		string tem = "";
		for( int i = 0; i < str.size(); i++){
			if( str[i] != ' ' ) 
				tem += str[i];
			else{
				data.push_back(tem);
				tem.clear();
			}
		}
		data.push_back(tem);
		vector<string> hash(128,"");
		if(data.size() - pattern.size()) return false;
		for(int i = 0; i< size; i++){
			if((hash[pattern[i]].compare("")) && ( hash[pattern[i]].compare(data[i]) ) )return false;
			if(!(hash[pattern[i]].compare(""))) hash[pattern[i]] = data[i];
		}
		for(int i = 0; i < 128; i++) {
			if(!hash[i].compare("")) continue;
			for( int j = 0; j< 128; j++){
				if( !hash[i].compare(hash[j]) && (i-j)) return false;
			}
		}
		return true;
    }
	/// 0ms
	/// 用两个map，构造两个哈希表，避免多对一的情况。
	//bool wordPattern(string pattern, string str) {
 //       istringstream strcin(str);
 //       string s;
 //       vector<string> vs;
 //       while(strcin >> s) vs.push_back(s);
 //       if (pattern.size() != vs.size()) return false;
 //       map<string, char> s2c;
 //       map<char, string> c2s;
 //       for (int i = 0; i < vs.size(); ++i) {
 //           if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
 //               s2c[vs[i]] = pattern[i]; 
 //               c2s[pattern[i]] = vs[i]; 
 //               continue; 
 //           }
 //           if (s2c[vs[i]] != pattern[i]) return false;
 //       }
 //       return true;
 //   }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	string p1 = "abba",
//		p2 = "aaaa",
//		p3 = "jquery",
//		str1 = "dog cat cat dog",
//		str2 = "dog cat cat fish",
//		str3 = "dog cat cat dog",
//		str4 = "dog dog dog dog";
//	//slt.wordPattern(p1,str1);
//	//slt.wordPattern(p1,str2);
//	//slt.wordPattern(p2,str3);
//	//slt.wordPattern(p1,str4);
//	slt.wordPattern(p3,p3);
// 	//system("pause");
//}
