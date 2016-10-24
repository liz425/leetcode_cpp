//
//  062_Uique_Paths.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //DP solution, rolling array
public:
    int uniquePaths(int m, int n) {
        if(m < n)
            swap(m, n);
        int dp[2][n];
        dp[0][0] = 1;
        for(int i = 1; i < n; ++i){
            dp[0][i] = dp[0][i - 1];
        }
        for(int i = 1; i < m; ++i){
            dp[i % 2][0] = dp[(i - 1) % 2][0];
            for(int j = 1; j < n; ++j){
                dp[i % 2][j] = dp[(i - 1) % 2][j] + dp[i % 2][j - 1];
            }
        }
        return dp[(m - 1) % 2][n - 1];
    }
};



class Solution {
    //Combination, choose (n - 1) down steps from total (m + n -2) steps
    //Notice that cnt here may overflow. Use long instead.
public:
    int uniquePaths(int m, int n) {
        if(--m < --n){
            swap(m, n);
        }
        long cnt = 1;   //note that cnt may overflow
        for(int i = 1; i <= n; ++i){
            cnt = cnt * (m + i) / i;
        }
        return (int)cnt;
    }
};
