/*
338. Counting Bits   My Submissions QuestionEditorial Solution
Total Accepted: 18249 Total Submissions: 32918 Difficulty: Medium
Given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include"leetcode.h"



class Solution {
public:
	/// O(n * 32); 144ms
	//vector<int> countBits(int num) {
	//	int bit = 32;
	//	vector<int> res;
	//	int tem = 0;
	//	for( int i = 0; i <= num; i++ ){
	//		bit = 32;
	//		tem = 0;
	//		while(bit--) tem += ((i>>bit)&1);
	//		res.push_back(tem);
	//	}
	//	return res;
	//}
	/// O(n) 124ms
	vector<int> countBits(int num){
		vector<int> res;
		res.push_back(0);
		if(num)res.push_back(1);
		for( int i = 2; i <= num; i++ ) {
			if( i % 2 ) res.push_back( res[i-1] + 1 );
			else{
				res.push_back( res[i/2] );
			}
		}
		return res;
	}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.countBits(2);
// 	//system("pause");
//}
