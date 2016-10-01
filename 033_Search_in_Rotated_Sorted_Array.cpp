//
//  033_Search_in_Rotated_Sorted_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //Check Jiuzhang Algo., Basic Chap2 to get more details.
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int start = 0, end = (int)nums.size() - 1;
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[start]){
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }else{
                if(target >= nums[mid] && target <= nums[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }
        }
        if(target == nums[start])
            return start;
        if(target == nums[end])
            return end;
        return -1;
    }
};
