/*
137. Single Number II   My Submissions QuestionEditorial Solution
Total Accepted: 82469 Total Submissions: 218962 Difficulty: Medium
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*********************************************************

                      follow up

*********************************************************
public int singleNumber(int[] A) {
    int ones = 0, twos = 0;
    for(int i = 0; i < A.length; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}

The code seems tricky and hard to understand at first glance. However, if you consider the problem in Boolean algebra form, everything becomes clear.

What we need to do is to store the number of '1's of every bit. Since each of the 32 bits follow the same rules, we just need to consider 1 bit. We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.

In this solution, 00, 01 and 10 are chosen. Let 'ones' represents the first bit, 'twos' represents the second bit. Then we need to set rules for 'ones' and 'twos' so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).

For 'ones', we can get 'ones = ones ^ A[i]; if (twos == 1) then ones = 0', that can be tansformed to 'ones = (ones ^ A[i]) & ~twos'.

Similarly, for 'twos', we can get 'twos = twos ^ A[i]; if (ones* == 1) then twos = 0' and 'twos = (twos ^ A[i]) & ~ones'. Notice that 'ones*' is the value of 'ones' after calculation, that is why twos is calculated later.

Here is another example. If a number appears 5 times at most, we can write a program using the same method. Now we need 3 bits and the loop is 000->100->010->110->001. The code looks like this:

int singleNumber(int A[], int n) {
    int na = 0, nb = 0, nc = 0;
    for(int i = 0; i < n; i++){
        nb = nb ^ (A[i] & na);
        na = (na ^ A[i]) & ~nc;
        nc = nc ^ (A[i] & ~na & ~nb);
    }
    return na & ~nb & ~nc;
}
Or even like this:

int singleNumber(int A[], int n) {
    int twos = 0xffffffff, threes = 0xffffffff, ones = 0;
    for(int i = 0; i < n; i++){
        threes = threes ^ (A[i] & twos);
        twos = (twos ^ A[i]) & ~ones;
        ones = ones ^ (A[i] & ~twos & ~threes);
    }
    return ones;
}
方法：使用掩码变量：

ones 代表第ith位只出现一次的掩码变量

twos 代表第ith位只出现两次次的掩码变量

threes 代表第ith位只出现三次的掩码变量

当第ith位出现3次时，我们就ones和twos的第ith位设置为0. 最终的答案就是 ones。

I hope all these above can help you have a better understand of this problem.
*/

#include"leetcode.h"
/// n&~(n-1);找出n的最低一位1，即the rightmost set bit.



class Solution {
public:
	/// 36ms
  //  int singleNumber(vector<int>& nums) {
		//int bit[32] = {0};
		//int res = 0;
		//auto iter = nums.begin();
		//for( int i = 0; i < 32; i++ ){
		//	iter = nums.begin();
		//	while(iter != nums.end()) {
		//		bit[i] += ((*iter++ >> i)&1);
		//	}
		//}
		//for( int i = 0; i < 32; i++ ){
		//	res += ((bit[i] % 3)<<i);
		//}
		//return res;
  //  }
	/// 16ms
	//int singleNumber(vector<int>& nums) {
	//	int bit[32] = {0};
	//	int res = 0;
	//	auto iter = nums.begin();
	//	while(iter != nums.end()) {
	//	    int c = *iter++;
 //   		for( int i = 0; i < 32; i++ ){
 //   		    bit[i] += (c&1);
 //   		    c>>=1;
 //   		}
	//	}
	//	for( int i = 0; i < 32; i++ ){
	//		res += ((bit[i] % 3)<<i);
	//	}
	//	return res;
 //   }
	/// 12ms
    //int singleNumber(vector<int>& nums) {
    //    // 只出现一次的掩码变量， 
    //    int ones = 0; 
    //    // 只出现两次次的掩码变量 
    //    int twos = 0; 
    //    // 只出现三次的掩码变量 
    //    int threes; 
    //    for (int i = 0; i < nums.size(); i++ ) { 
    //        twos |= ones & nums[i]; 
    //        // 异或3次 和 异或 1次的结果是一样的 
    //        ones ^= nums[i]; 
    //        // 对于ones和twos把出现了3次的位置设置为0（取反之后1的位置为0） 
    //        threes = ones & twos; 
    //        ones &= ~threes; 
    //        twos &= ~threes; 
    //    } 
    //    return ones; 
    //}
	/// self 12ms
	int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        auto iter = nums.begin();
        while( iter != nums.end() ){
            two |= one & *iter;
            one ^= *iter;
            three = one & two;
            one &= ~three;
            two &= ~three;
            iter++;
        }
        return one;
    }
};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
//	int a[16] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6};
//	vector<int>vec(a,a+16);
//	slt.singleNumber(vec);
// 	//system("pause");
//}
