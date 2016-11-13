//
//  78_Subsets.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<vector<int>> result;
    void DFS(vector<int>& candids, vector<int>& nums, int k){
        if(k == (int)nums.size()){
            result.push_back(candids);
            return;
        }
        DFS(candids, nums, k + 1);
        candids.push_back(nums[k]);
        DFS(candids, nums, k + 1);
        candids.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> candids;
        DFS(candids, nums, 0);
        return result;
    }
};
