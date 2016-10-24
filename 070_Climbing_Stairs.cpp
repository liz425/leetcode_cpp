//
//  070_Climbing_Stairs.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int climbStairs(int n) {
        int dp[3] = {1, 1, 0};
        for(int i = 2; i <= n; ++i){
            dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];
        }
        return dp[n % 2];
    }
};
