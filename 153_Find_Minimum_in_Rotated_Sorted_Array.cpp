//
//  153_Find_Minimum_in_Rotated_Sorted_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int)nums.size() - 1;
        if(nums[left] < nums[right])
            return nums[left];
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[0])
                right = mid;
            else
                left = mid;
        }
        return min(nums[left], nums[right]);
    }
};
