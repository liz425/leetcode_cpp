//
//  152_Maximum_Product_Subarray.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/13/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //This is actually a DP solution
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int localMax = nums[0], localMin = nums[0], globalMax = nums[0];
        for(int i = 1; i < (int)nums.size(); ++i){
            int tmp = localMax;
            localMax = max(max(nums[i] * localMax, nums[i] * localMin), nums[i]);
            localMin = min(min(nums[i] * tmp, nums[i] * localMin), nums[i]);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};
