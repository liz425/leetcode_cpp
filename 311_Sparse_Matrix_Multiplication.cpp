//
//  311_Sparse_Matrix_Multiplication.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Faster solution.
    //since A is sparse matrix, only for rare times will the third loop be entered.
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = (int)A.size(), p = (int)B.size(), n = (int)B[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < p; ++j){
                if(A[i][j] != 0){
                    for(int k = 0; k < n; k++)
                        result[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    //use 2 sparse matrix to store only non-zero element position
    //Theoritically, this should be fast.
    //BUT in real test, this method is slower than solution2, which is somehow brutal-force in matrix B
    //Consider the following matrix (both A and B)
    //
    //     1 1 1 1 1
    //     1 0 0 0 0
    //     1 0 0 0 0
    //     1 0 0 0 0
    //     1 0 0 0 0
    //
    //Though it's sparse matrix, but non of the sparseA[i] or sparseB[i] is empty. Thus it's slow
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = (int)A.size(), k = (int)B.size(), n = (int)B[0].size();
        vector<vector<int>> sparseA(m, vector<int>(0, 0));
        vector<vector<int>> sparseB(n, vector<int>(0, 0));
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < k; ++j){
                if(A[i][j] != 0)
                    sparseA[i].push_back(j);
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < k; ++j){
                if(B[j][i] != 0)
                    sparseB[i].push_back(j);
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(sparseA[i].empty() || sparseB[j].empty())
                    continue;
                vector<int> intersec(min(sparseA[i].size(), sparseB[j].size()));
                vector<int>::iterator it = set_intersection(sparseA[i].begin(), sparseA[i].end(), sparseB[j].begin(), sparseB[j].end(), intersec.begin());
                intersec.resize(it - intersec.begin());
                for(auto& index : intersec){
                    result[i][j] += A[i][index] * B[index][j];
                }
            }
        }
        return result;
    }
};


/*
int main(){
    Solution2 ss;
    vector<vector<int>> A = {{1,0,0},{1,0,0}};
    vector<vector<int>> B = {{7,0,0},{0,0,0},{0,0,1}};
    vector<vector<int>> result = ss.multiply(A, B);
    return 0;
}
*/
