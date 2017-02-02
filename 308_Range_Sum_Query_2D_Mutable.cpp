//
//  308_Range_Sum_Query_2D_Mutable.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class NumMatrix2 {
    //T = O(logm * logn)
    //Improvement based on Solution1: do not need to store original matrix.
    //Use queryNode(row, col) to get the original data of some node. Then can update.
private:
    vector<vector<int>> tree;   //BIT tree
    int m;
    int n;
    void add(int row, int col, int delta){
        int i = row + 1;
        while(i <= m){
            int j = col + 1;
            while(j <= n){
                tree[i][j] += delta;
                j += j & (-j);
            }
            i += i & (-i);
        }
        return;
    }
    int querySum(int row, int col){
        int i = row + 1;
        int sum = 0;
        while(i > 0){
            int j = col + 1;
            while(j > 0){
                sum += tree[i][j];
                j -= j & (-j);
            }
            i -= i & (-i);
        }
        return sum;
    }
    int queryNode(int row, int col){
        return sumRegion(row, col, row, col);
    }
public:
    NumMatrix2(vector<vector<int>> &matrix){
        if(matrix.empty() || matrix[0].empty()){
            return;
        }
        m = (int)matrix.size();
        n = (int)matrix[0].size();
        tree.assign(m + 1, vector<int>(n + 1, 0));
        //build tree
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                add(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - queryNode(row, col);
        add(row, col, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return querySum(row2, col2) + querySum(row1 - 1, col1 - 1) - querySum(row1 - 1, col2) - querySum(row2, col1 - 1);
    }
};


class NumMatrix {
    //T = O(logm * logn)
private:
    vector<vector<int>> tree;
    vector<vector<int>>& _matrix;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>> &matrix):_matrix(matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return;
        }
        m = (int)_matrix.size();
        n = (int)_matrix[0].size();
        tree = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                add(i, j, _matrix[i][j]);
            }
        }
    }
    void add(int row, int col, int delta){
        row++;  //1-based
        col++;
        for(int i = row; i <= m; i += (-i & i)){
            for(int j = col; j <= n; j += (-j & j)){
                tree[i][j] += delta;
            }
        }
    }
    void update(int row, int col, int val) {
        int delta = val - _matrix[row][col];
        _matrix[row][col] = val;
        add(row, col, delta);
    }
    int sum(int row, int col){
        int result = 0;
        row++;
        col++;
        for(int i = row; i > 0; i -= (-i & i)){
            for(int j = col; j > 0; j -= (-j & j)){
                result += tree[i][j];
            }
        }
        return result;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) + sum(row1 - 1, col1 - 1) - sum(row1 - 1, col2) - sum(row2, col1 - 1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
