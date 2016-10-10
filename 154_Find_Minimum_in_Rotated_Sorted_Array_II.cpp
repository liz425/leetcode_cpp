//
//  154_Find_Minimum_in_Rotated_Sorted_Array_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;
        while(left + 1 < right){
            if(nums[left] < nums[right])
                break;
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                left = mid;
            else if(nums[mid] < nums[right])
                right = mid;
            else
                left++;
        }
        return min(nums[left], nums[right]);
    }
};
