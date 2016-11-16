/**
在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。
给定一个整数n，请返回n位的格雷码，顺序为从0开始。
测试样例：
1
返回：["0","1"]
2
返回：["00","01","11","10"]

*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> getGray(int n) {
        // write code here
		string res;
        vector<string> resv;
        if(n==0) {
			return resv;
		}
        if(n == 1) {
			res = "0";
			resv.push_back(res);
			res = "1";
			resv.push_back(res);
			return resv;
        }
		vector<string> res1 = getGray(n-1);
		int i = 0;
		for( i = 0; i< res1.size(); i++ ) {
			res = "0";
			res += res1[i];
			resv.push_back(res);
		}
		for( i = res1.size() - 1; i >= 0 ; i--) {
			res = "1";
			res += res1[i];
			resv.push_back(res);
		}
		return resv;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	vector<string> res = s.getGray(2);
//	cout<<res.size()<<endl;
// 	system("pause");
//}