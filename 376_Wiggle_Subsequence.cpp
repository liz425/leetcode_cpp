//
//  376_Wiggle_Subsequence.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/14/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        int flag = 0;   //previous status, 0: start(no previous or equal), 1: increase, -1: decrease
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1]){
                dp[i] = dp[i - 1];
            }else{
                if(flag == 0){
                    dp[i] = dp[i - 1] + 1;
                    flag = (nums[i] > nums[i - 1])? 1 : -1;
                }else if(flag == 1){
                    if(nums[i] > nums[i - 1]){
                        dp[i] = dp[i - 1];
                    }else{
                        dp[i] = dp[i - 1] + 1;
                        flag = -1;
                    }
                }else{
                    if(nums[i] < nums[i - 1]){
                        dp[i] = dp[i - 1];
                    }else{
                        dp[i] = dp[i - 1] + 1;
                        flag = 1;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
