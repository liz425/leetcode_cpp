//
//  416_Partition_Equal_Subset_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/29/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Use bitset. Basically the same idea of DP.
    //But bitset can be shifted and applied bit operation as a whole part.
    //It reduce the inner for-loop in DP solution into a single statement: bits |= bits << n.
    //So the time reduced significantly.
public:
    bool canPartition(vector<int>& nums) {
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
        int sum = 0;
        for (auto n : nums) {
            sum += n;
            bits |= bits << n;
        }
        return !(sum % 2) && bits[sum / 2];
    }
};


class Solution {
    //DP. T = O(n * S), S = sum / 2
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){
            return false;
        }else{
            int target = sum / 2;
            vector<bool> dp(target + 1, false);
            dp[0] = true;
            for(auto& num : nums){
                for(int i = target; i >= num; --i){
                    dp[i] = dp[i] || dp[i - num];
                }
            }
            return dp[target];
        }
    }
};


