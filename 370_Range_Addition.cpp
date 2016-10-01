//
//  370_Range_Addition.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length + 1, 0);
        for(auto& update : updates){
            nums[update[0]] += update[2];
            nums[update[1] + 1] -= update[2];
        }
        int pre = 0;
        for(int i = 0; i < length; ++i){
            nums[i] += pre;
            pre = nums[i];
        }
        nums.pop_back();
        return nums;
    }
};
