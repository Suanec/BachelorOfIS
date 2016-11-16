/**
之字形打印矩阵 printMatrix
参与人数：879时间限制：3秒空间限制：32768K
本题知识点： 数组 编程基础
 算法知识视频讲解
题目描述

对于一个矩阵，请设计一个算法，将元素按“之”字形打印。具体见样例。
给定一个整数矩阵mat，以及他的维数nxm，请返回一个数组，其中元素依次为打印的数字。
测试样例：
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]],4,3
返回：[1,2,3,6,5,4,7,8,9,12,11,10]
==================================================================
顺时针打印矩阵 clockwisePrint
参与人数：612时间限制：3秒空间限制：32768K
本题知识点： 数组 模拟
 算法知识视频讲解
题目描述

对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。
给定int矩阵mat,以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
测试样例：
[[1,2],[3,4]],2,2
返回：[1,2,4,3]
[[4,46,89],[28,66,99],[26,21,71]],3,3
==================================================================
顺时针旋转矩阵 rotateMatrix
参与人数：756时间限制：3秒空间限制：32768K
本题知识点： 编程基础
 算法知识视频讲解
题目描述

有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于300。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
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