/*
13. Roman to Integer   My Submissions QuestionEditorial Solution
Total Accepted: 82111 Total Submissions: 209437 Difficulty: Easy
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

罗马数字规则：
1.相同的数字连写、所表示的数等于这些数字相加得到的数、如：Ⅲ=3；
2.小的数字在大的数字的右边、所表示的数等于这些数字相加得到的数、 如：Ⅷ=8、Ⅻ=12；
3.小的数字、（限于 Ⅰ、X 和 C）在大的数字的左边、所表示的数等于大数减小数得到的数、如：Ⅳ=4、Ⅸ=9；
4.正常使用时、连写的数字重复不得超过三次；
5.在一个数的上面画一条横线、表示这个数扩大 1000 倍。
*/

#include"leetcode.h"



class Solution {
public:
	/// 36ms
	int romanChar2Int( char c ){
		switch( c ){
		case 'I' : return 1;
		case 'V' : return 5;
		case 'X' : return 10;
		case 'L' : return 50;
		case 'C' : return 100;
		case 'D' : return 500;
		case 'M' : return 1000;
		default : return -1;
		}
	}
    int romanToInt(string s) {
		int size = s.size();
		if( !size ) return 0;
		int i = 0;
		char tem = ' ';
		int sum = 0;
		char c = ' ';
		while( i < size ){
			c = s[i];
			int plus = romanChar2Int(c);
			if( !(i+1 - size) ){
				sum += plus;
				i++;
				continue;
			}
			else if( ('I' == c || 'X' == c || 'C' == c) && ( plus < romanChar2Int(s[i+1]) ) ){
				plus *= -1;
			}
			sum += plus;
			i++;
		}
		return sum;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a = slt.romanChar2Int('D');
//	string str = "MCMLXXX";
//	int a = slt.romanToInt(str);
// 	system("pause");
//}
