/*
168. Excel Sheet Column Title   My Submissions QuestionEditorial Solution
Total Accepted: 59968 Total Submissions: 275603 Difficulty: Easy
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/


#include"leetcode.h"



class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
		char c[2] = {'\0'};
		if( !(n-26) ) return "Z";
		if( !(n/26) ){
			c[0] = 'A' + n -1;
			res += c;
			return res;
		}
		if( !(n%26) ) res = convertToTitle(n/26 -1);
		else res = convertToTitle(n/26);
		c[0] = 'A' + (n%26) -1;
		if( c[0]+1 == 'A' ) c[0] = 'Z';
		res += c;
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	char c[2] = {0};
//	c[0] = 'A';
//	string str;
//	str += c;
//	slt.convertToTitle(2);
//	slt.convertToTitle(1);
//	slt.convertToTitle(29);
//	slt.convertToTitle(26*26);
//	slt.convertToTitle(52);
// 	//system("pause");
//}
