//
//  209_Minimum_Size_Subarray_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = (int)nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                //note here has an assumption: s > 0, which is given by the description,
                //otherwise when sum == 0, still go into the loop, and nums[start++] may out of index
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
