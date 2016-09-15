//
//  312_Burst_Balloons.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
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