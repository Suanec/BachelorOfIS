/**
֮���δ�ӡ���� printMatrix
����������879ʱ�����ƣ�3��ռ����ƣ�32768K
����֪ʶ�㣺 ���� ��̻���
 �㷨֪ʶ��Ƶ����
��Ŀ����

����һ�����������һ���㷨����Ԫ�ذ���֮�����δ�ӡ�������������
����һ����������mat���Լ�����ά��nxm���뷵��һ�����飬����Ԫ������Ϊ��ӡ�����֡�
����������
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]],4,3
���أ�[1,2,3,6,5,4,7,8,9,12,11,10]
==================================================================
˳ʱ���ӡ���� clockwisePrint
����������612ʱ�����ƣ�3��ռ����ƣ�32768K
����֪ʶ�㣺 ���� ģ��
 �㷨֪ʶ��Ƶ����
��Ŀ����

����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�
����int����mat,�Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������
����������
[[1,2],[3,4]],2,2
���أ�[1,2,4,3]
[[4,46,89],[28,66,99],[26,21,71]],3,3
==================================================================
˳ʱ����ת���� rotateMatrix
����������756ʱ�����ƣ�3��ռ����ƣ�32768K
����֪ʶ�㣺 ��̻���
 �㷨֪ʶ��Ƶ����
��Ŀ����

��һ��NxN�����������дһ���㷨��������˳ʱ����ת90�ȡ�
����һ��NxN�ľ��󣬺;���Ľ���N,�뷵����ת���NxN����,��֤NС�ڵ���300��
����������
[[1,2,3],[4,5,6],[7,8,9]],3
���أ�[[7,4,1],[8,5,2],[9,6,3]]
*/
#include"leetcode.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
        // write code here
		vector<int> res;
		for(int i = 0; i < n; i++){
			vector<int> tem = mat[i];
			if( !(i % 2) ){
				for(int j = 0; j < m; j++){
					res.push_back( tem[j] );
				}
			}
			else{
				for(int j = m-1; j >= 0; j--){
					res.push_back( tem[j] );
				}
			}
		}
		return res;
    }
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
		int minDim = (( n > m ) ? m : n );
		int cele =  ( minDim%2 ) ? (minDim / 2 +1) : (minDim / 2) ;
		int allNum = m*n;
		int num = 0;
		vector<int> res ;
		for( int circle = 1; circle <= cele ; circle++ ) {
			//vector<int> line1 = mat[circle-1];
			//vector<int> line2 = mat[n-circle];
			int row1 = circle -1;
			int row2 = n - circle;
			int col1 = circle -1;
			int col2 = m - circle;
			for( int i = col1 ; i <= col2; i++ ){
				res.push_back( mat[row1][i] );
				num ++;
			}
			if( !(allNum - num ) ) break;
			for( int i = row1+1 ; i <= row2; i++ ){
				res.push_back( mat[i][col2] );
				num++;
			}
			if( !(allNum - num ) ) break;
			for( int i = col2-1 ; i >= col1; i-- ){
				res.push_back( mat[row2][i] );
				num++;
			}
			if( !(allNum - num ) ) break;
			for( int i = row2-1 ; i > row1; i-- ){
				res.push_back( mat[i][col1] );
				num++;
			}
			if( !(allNum - num ) ) break;

		}
		return res;
    }
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
		vector<vector<int> > res ;
		vector< int > tem;
		for( int i = 0 ; i < n ; i++ ) {
			for( int j = n-1; j>=0 ; j-- ) {
				tem.push_back(mat[j][i]);
			}
			res.push_back(tem);
			tem.clear();
		}
		return res;
    }
};

/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution s;
//	int a[] = {4,46,89};
//	int b[] = {28,66,99};
//	int c[] = {26,21,71};
//	vector<vector<int>> a1 ;
//	vector<int> a2;
//	a2.assign(a, a+3);
//	a1.push_back(a2);
//	a2.assign(b, b+3);
//	a1.push_back(a2);
//	a2.assign(c,c+3);
//	a1.push_back(a2);
//	c[0] = 0;
//	c[1] = 1;
//	c[2] = 2;
//	a2.assign(c,c+3);
//	int t = 3/2;
//	a1.push_back(a2);
//	//a1.assign(a,a+7);
//	vector<int> res = s.clockwisePrint(a1,3,3);
//
//	//int res = s.getValue(a1,7);
//	//cout<<res<<endl;
// 	system("pause");
//}