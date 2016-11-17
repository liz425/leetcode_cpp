//
//  080_Remove_Duplicates_from_Sorted_Array_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //T = O(n), Space = O(1)
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int slow = 1, fast = 1, cnt = 1;
        for(fast = 1; fast < (int)nums.size(); ++fast){
            if(nums[fast] != nums[fast - 1]){
                nums[slow++] = nums[fast];
                cnt = 1;
            }else if(nums[fast] == nums[fast - 1] && cnt < 2){
                nums[slow++] = nums[fast];
                cnt++;
            }
        }
        return slow;
    }
};
