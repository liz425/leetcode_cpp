//
//  304_Range_Sum_Query_2D_Immutable.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class NumMatrix {
private:
    vector<vector<int>> sum;
    int m, n;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = (int)matrix.size();
        if(m > 0){
            n = (int)matrix[0].size();
        }else{
            n = 0;
        }
        sum.assign(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = max(row1, 0);
        col1 = max(col1, 0);
        row2 = min(row2, m - 1);
        col2 = min(col2, n - 1);
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
