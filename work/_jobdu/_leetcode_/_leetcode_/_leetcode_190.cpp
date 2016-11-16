/*
190. Reverse Bits   My Submissions QuestionEditorial Solution
Total Accepted: 60640 Total Submissions: 207145 Difficulty: Easy
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/

#include"leetcode.h"

class Solution {
public:
	/// 8ms --> 4ms i++�Ƶ�while�ж���ٶ�������
    uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		int i = 0;
		while( i++ < 32 ) {
			res <<= 1;
			res |= n & 1;
			n>>=1;
		}
		return res;
    }
	///  merge sort --> Divide and Conquer!
    //uint32_t reverseBits(uint32_t n) {
	
    //    n = (n >> 16) | (n << 16);/// ǰ��16λ����
    //    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);/// �����ֵ�ǰ��8λ����
    //    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);/// �Ĳ��ֵ�ǰ��4λ����
    //    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);/// �˲��ֵ�ǰ��2λ����, c=12 = 1100, 3 = 0011;
    //    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);/// ������λǰ�󽻻���   a = 10 = 1010, 5 = 0101
    //    return n;
    //}
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	slt.reverseBits(43261596);
//	
// 	//system("pause");
//}
