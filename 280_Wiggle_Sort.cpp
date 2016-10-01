//
//  280_Wiggle_Sort.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

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
