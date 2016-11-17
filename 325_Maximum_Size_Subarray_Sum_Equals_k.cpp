//
//  325_Maximum_Size_Subarray_Sum_Equals_k.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int maxLen = 0, sum = 0;
        //hash[sum] indicate the first index of the leading nums sum
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(hash.find(sum) == hash.end())
                hash[sum] = i;
            if(hash.find(sum - k) != hash.end())
                maxLen = max(maxLen, i - hash[sum - k]);
        }
        return maxLen;
    }
};
