//
//  046_Permutations.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void permute_helper(int k, vector<int>& nums, vector<vector<int>>& rtn){
        if(k == 1){
            rtn.push_back(nums);
        }
        for(int i = 0; i < k; i++){
            vector<int> boring = nums;
            boring[i] = nums[k - 1];
            boring[k - 1] = nums[i];
            permute_helper(k - 1, boring, rtn);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rtn;
        permute_helper((int)nums.size(), nums, rtn);
        return rtn;
    }
};