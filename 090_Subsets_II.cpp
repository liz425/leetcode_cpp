//
//  090_Subsets_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS: the j-level DFS is responsible for choosing the j-th element in the subset
    //So DFS should choose different element in the loop
public:
    void DFS(vector<int>& candid, vector<int>& nums, int k, vector<vector<int>>& result){
        result.push_back(candid);
        for(int i = k; i < (int)nums.size(); ++i){
            if(i > k && nums[i] == nums[i - 1]){
                continue;
            }
            candid.push_back(nums[i]);
            DFS(candid, nums, i + 1, result);
            candid.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> candid;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        DFS(candid, nums, 0, result);
        return result;
    }
};
