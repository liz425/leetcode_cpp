//
//  046_Permutations.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //At current level, chose one element from the leading K elements and swap it with the k-th element (k is 1-base)
    void dfs(int k, vector<int>& nums, vector<vector<int>>& result){
        if(k == 1){
            result.push_back(nums);
        }
        for(int i = 0; i < k; i++){
            swap(nums[i], nums[k - 1]);
            dfs(k - 1, nums, result);
            swap(nums[i], nums[k - 1]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs((int)nums.size(), nums, result);
        return result;
    }
};
