/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
方法一：普通矩阵乘法
[java] view plain copy
public class Solution {  
    public int[][] multiply(int[][] A, int[][] B) {  
        int[][] C = new int[A.length][B[0].length];  
        for(int i=0; i<A.length; i++) {  
            for(int j=0; j<A[i].length; j++) {  
                if (A[i][j] == 0) continue;  
                for(int k=0; k<B[0].length; k++) {  
                    if (B[j][k] == 0) continue;  
                    C[i][k] += A[i][j] * B[j][k];  
                }  
            }  
        }  
        return C;  
    }  
}  
方法二：使用哈希映射来存放非0数字。
[java] view plain copy
public class Solution {  
    private Map<Integer, Map<Integer, Integer>> map(int[][] m) {  
        Map<Integer, Map<Integer, Integer>> rows = new HashMap<>();  
        for(int i=0; i<m.length; i++) {  
            for(int j=0; j<m[i].length; j++) {  
                if (m[i][j]==0) continue;  
                Map<Integer, Integer> cols = rows.get(i);  
                if (cols == null) {  
                    cols = new HashMap<>();  
                    rows.put(i, cols);  
                }  
                cols.put(j, m[i][j]);  
            }  
        }  
        return rows;  
    }  
    public int[][] multiply(int[][] A, int[][] B) {  
        int[][] C = new int[A.length][B[0].length];  
        Map<Integer, Map<Integer, Integer>> arows = map(A);  
        Map<Integer, Map<Integer, Integer>> brows = map(B);  
        for(int i: arows.keySet()) {  
            Map<Integer, Integer> acol = arows.get(i);  
            for(int j: acol.keySet()) {  
                Map<Integer, Integer> bcol = brows.get(j);  
                if (bcol == null) continue;  
                int a = acol.get(j);  
                for(int l: bcol.keySet()) {  
                    C[i][l] += a * bcol.get(l);  
                }  
            }  
        }  
        return C;  
    }  
}  

*/

#include"leetcode.h"


/// naive solution
//class Solution {
//public:
//    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
//        int m = A.size(), n = A[0].size();
//        vector<vector<int>> res(m, vector<int>(B[0].size(),0));
//
//        // for(int i = 0; i < m; i++){
//        //     for(int k = 0; k < n; k++){
//        //          for(int j = 0; j < n; j++){
//        //              res[i][j] += A[i][k] * B[k][j];
//        //          }
//        //     }
//        // }
//        // imporved on upper version, this is a math solution
//        for(int i = 0; i < m; i++){
//            for(int k = 0; k < n; k++){
//                if(A[i][k] != 0)
//                    for(int j = 0; j < B[0].size(); j++){
//                        res[i][j] += A[i][k] * B[k][j];
//                    }
//            }
//        }
//        return res;
//    }
//};
/// 48ms
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();
		/// the iterators
        int i, j, k, a, b;
		/// the res Matrix C 
        vector<vector<int>> C;
        C.resize(m);
        for(i=0; i<m; i++)
            C[i].resize(n, 0);
		/// Map stored A 
        unordered_map<int, unordered_map<int, int>> AMap;
        for(i=0; i<m; i++)
            for(j=0; j<p; j++)
                if(A[i][j] != 0)
                    AMap[i][j] = A[i][j];
		/// Map stored B
		/// BMap stored Matrix B's translator
        unordered_map<int, unordered_map<int, int>> BMap;
        for(j=0; j<p; j++)
            for(k=0; k<n; k++)
                if(B[j][k] != 0)
                    BMap[k][j] = B[j][k];

        for(auto ia=AMap.begin(); ia!=AMap.end(); ia++)
        {
			/// ia iterAMap
			/// ra row in AMap
            auto ra = ia->second;
			/// i the row number of current row
            i = ia->first;
            for(auto ib=BMap.begin(); ib!=BMap.end(); ib++)
            {
                auto rb = ib->second;
                k = ib->first;/// k is the number of column in B. That's to says the row in BMap
                for(auto ia2=ra.begin(); ia2!=ra.end(); ia2++)
                {
                    j = ia2->first;/// the B's row number
                    a = ia2->second;
                    if(rb.find(j) != rb.end())
                    {
                        b = rb[j];
                        C[i][k] += a*b;
                    }
                }
            }
        }

        return C;
    }
};
/*********************************************************

                         main()

*********************************************************/
//void main(){
//	Solution slt;
// 	//system("pause");
//}
