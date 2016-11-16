/*
13. Roman to Integer   My Submissions QuestionEditorial Solution
Total Accepted: 82111 Total Submissions: 209437 Difficulty: Easy
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

�������ֹ���
1.��ͬ��������д������ʾ����������Щ������ӵõ��������磺��=3��
2.С�������ڴ�����ֵ��ұߡ�����ʾ����������Щ������ӵõ������� �磺��=8����=12��
3.С�����֡������� ��X �� C���ڴ�����ֵ���ߡ�����ʾ�������ڴ�����С���õ��������磺��=4����=9��
4.����ʹ��ʱ����д�������ظ����ó������Σ�
5.��һ���������滭һ�����ߡ���ʾ��������� 1000 ����
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
