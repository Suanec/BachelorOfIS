/**
[编程题] 微信红包
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
测试样例：
[1,2,3,2,2],5
返回：2
*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
		int res = gifts[0];
		int cnt = 1;
		for( int i = 1; i < n; i++ ){
			if( res == -1 ) {
				res = gifts[i];
				cnt ++;
			}
			else if( gifts[i] == res ) cnt ++;
			else if( (cnt - 1) ) cnt--;
			else {
				res = -1;
				cnt = 0;
			}
		}
		cnt = 0;
		for( int i = 0; i < n; i++) {
			if( res == gifts[i] ) cnt ++;
		}
		if( !cnt ) return 0;
		if( n % cnt ) return res;
		else return 0;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	int a[] = {37256,61520,11540,61520,69323,61520,61520};
//	vector<int> a1 ;
//	a1.assign(a,a+7);
//	int res = s.getValue(a1,7);
//	cout<<res<<endl;
// 	system("pause");
//}