//
//  494_Target_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/29/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Converted into subSetSum problem, which is one of knapsack problem. Solved by DP.
    //  Sum(Positive) - Sum(Negtive) = target       (1)
    //  Sum(Positive) + Sum(Negtive) = Sum(nums)    (2)
    //  Combine (1) and (2), ==> Sum(Positive) = (target + Sum(nums)) / 2  ==> SubSetSum problem.
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((S + sum) % 2 || (S + sum) < 0 || sum < S){
            return 0;
        }else{
            return subSetSum(nums, (S + sum) / 2);
        }
    }
    int subSetSum(vector<int>& nums, int target){
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int& num : nums){
            for(int i = target; i >= num; --i){
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};


class Solution {
    //T = O(2^n). A pruned DFS solution, merge tree node at each new level
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> hms(2);
        hms[0][0] = 1;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i){
            hms[(i + 1) % 2].clear();
            for(auto& item : hms[i % 2]){
                hms[(i + 1) % 2][item.first + nums[i]] += item.second;
                hms[(i + 1) % 2][item.first - nums[i]] += item.second;
            }
        }
        return hms[n % 2][S];
    }
};
