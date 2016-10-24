//
//  064_Minimum_Path_Sum.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //rolling array optimized
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int dp[2][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < m; ++i){
            dp[i % 2][0] = dp[(i - 1) % 2][0] + grid[i][0];
            for(int j = 1; j < n; ++j){
                dp[i % 2][j] = min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]) + grid[i][j];
            }
        }
        return dp[(m - 1) % 2][n - 1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
