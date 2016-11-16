/**
[�����] ΢�ź��
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
����������
[1,2,3,2,2],5
���أ�2
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