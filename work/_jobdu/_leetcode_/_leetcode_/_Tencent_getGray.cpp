/**
��һ�����ı����У��������������ڵĴ���ֻ��һλ����������ͬ�� ������ֱ���Ϊ������(Gray Code)�����дһ��������ʹ�õݹ�ķ�������Nλ�ĸ����롣
����һ������n���뷵��nλ�ĸ����룬˳��Ϊ��0��ʼ��
����������
1
���أ�["0","1"]
2
���أ�["00","01","11","10"]

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