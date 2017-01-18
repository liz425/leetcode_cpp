//
//  280_Wiggle_Sort.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        if(n <= 1){
            return;
        }
        for(int i = 1; i < n; ++i){
            if((i % 2 == 1 && nums[i - 1] > nums[i]) || (i % 2 == 0 && nums[i - 1] < nums[i])){
                swap(nums[i - 1], nums[i]);
            }
        }
        return;
    }
};


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        bool ascend = true;
        for(int i = 1; i < nums.size(); ++i){
            if((nums[i] > nums[i-1] && !ascend) || (nums[i] < nums[i-1] && ascend)){
                swap(nums[i], nums[i - 1]);
            }
            ascend = !ascend;
        }
        return;
    }
};
