//
//  064_Minimum_Path_Sum.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int dp[n];
        dp[0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i - 1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[j] = dp[j] + grid[i][0];
                }else{
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
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