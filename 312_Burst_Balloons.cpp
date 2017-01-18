//
//  312_Burst_Balloons.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //Use iterative instead of recursive. Same idea.
    //T = O(n^3)
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> extend(n + 2, 1);
        for(int i = 0; i < n; ++i){
            extend[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int step = 1; step <= n; ++step){
            for(int i = 1; i + step - 1 <= n; ++i){
                int j = i + step - 1;
                for(int k = i; k <= j; ++k){
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + extend[k] * extend[i - 1] * extend[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};




class Solution2 {
    //Same idea, T = O(n^3)
private:
    vector<vector<int>> dp;
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        dp.assign(n, vector<int>(n, -1));
        return burst(nums, 0, n - 1, 1, 1);
    }
    int burst(vector<int>& nums, int i, int j, int left, int right){
        if(i > j){
            return 0;
        }else if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxC = 0;
        for(int k = i; k <= j; ++k){
            //burst kth ballon as the last one
            int coins = nums[k] * left * right + burst(nums, i, k - 1, left, nums[k]) + burst(nums, k + 1, j, nums[k], right);
            maxC = max(maxC, coins);
        }
        dp[i][j] = maxC;
        return maxC;
    }
};


class Solution {
    //T = O(n^3)
    //dp[i][j] means that, when i - 1 and j + 1 still remains, we burst [i,j] and record the most coins we can get.
    //if we burst i - 1 first, then try to calculate burst [i, j], thus the result should be put in dp[i - 1][j], not dp[i][j].
    //Thus, dp[i][j] has an assumption: the i - 1 and j + 1 ballons will be bursted later than [i, j]
public:
    int maxCoins(vector<int>& nums) {
        int size = (int)nums.size();
        vector<vector<int>> DP(size, vector<int>(size, -1));
        return DFS(nums, 0, size - 1, DP);
    }
    int getNum(vector<int>& nums, int i){
        if(i == -1 || i == int(nums.size()))
            return 1;
        else
            return nums[i];
    }
    int DFS(vector<int>& nums, int start, int end, vector<vector<int>>& DP){
        if(start > end)
            return 0;
        if(DP[start][end] > -1)
            return DP[start][end];
        int maxpoint = 0;
        for(int i = start; i <= end; ++i){
            maxpoint = max(maxpoint, DFS(nums, start, i - 1, DP) + DFS(nums, i + 1, end, DP) + getNum(nums, i) * getNum(nums, start - 1) * getNum(nums, end + 1));
        }
        DP[start][end] = maxpoint;
        //cout << maxpoint << endl;
        return maxpoint;
    }
};


/*
int main(){
    Solution ss;
    vector<int> nums = {};
    cout << ss.maxCoins(nums) << endl;
    return 0;
}
*/
