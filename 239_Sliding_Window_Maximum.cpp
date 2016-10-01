//
//  239_Sliding_Window_Maximum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = (int)nums.size();
        vector<int> result;
        deque<int> candid;
        if(nums.empty())
            return result;
        for(int i = 0; i < size; ++i){
            while(!candid.empty() && candid.back() < nums[i]){
                candid.pop_back();
            }
            candid.push_back(nums[i]);
            if(i >= k && candid.front() == nums[i - k])
                candid.pop_front();
            if(i >= k - 1)
                result.push_back(candid.front());
        }
        return result;
    }
};
