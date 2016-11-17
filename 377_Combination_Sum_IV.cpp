//
//  377_Combination_Sum_IV.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Do not need to sort
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> DP(target + 1, 0);
        DP[0] = 1;
        int n = (int)nums.size();
        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < n; j++){
                if(nums[j] <= i){
                    DP[i] += DP[i - nums[j]];
                }
            }
        }
        return DP[target];
    }
};



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < nums.size() && i - nums[j] >= 0; ++j){
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
