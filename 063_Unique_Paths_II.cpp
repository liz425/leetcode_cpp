//
//  063_Unique_Paths_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Using rolling array to reduce space consumption
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        int dp[2][n];
        dp[0][0] = 1 - obstacleGrid[0][0];  //If not obstacle, dp[0][0] = 1
        for(int i = 1; i < n; ++i){
            dp[0][i] = obstacleGrid[0][i]? 0: dp[0][i - 1];
        }
        for(int i = 1; i < m; ++i){
            dp[i % 2][0] = obstacleGrid[i][0]? 0 : dp[(i - 1) % 2][0];
            for(int j = 1; j < n; ++j){
                dp[i % 2][j] = obstacleGrid[i][j]? 0 : dp[(i - 1) % 2][j] + dp[i % 2][j - 1];
            }
        }
        return dp[(m - 1) % 2][n - 1];
    }
};




class Solution {
    //DP
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = (int)obstacleGrid.size();
        int m = (int)obstacleGrid[0].size();
        vector<vector<int>> dp (n, vector<int>(m, 0));
        dp[0][0] = (obstacleGrid[0][0] == 1)? 0 : 1;
        //initialize top boundary
        for(int i = 1; i < m; ++i){
            dp[0][i] = (obstacleGrid[0][i] == 1)? 0 : dp[0][i - 1];
        }
        for(int i = 1; i < n; ++i){
            dp[i][0] = (obstacleGrid[i][0] == 1)? 0 : dp[i - 1][0];
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

//int main(void){
//    vector<vector<int>> input = {{0,0}};
//  Solution ss;
//  cout << ss.uniquePathsWithObstacles(input) << endl;
//}
