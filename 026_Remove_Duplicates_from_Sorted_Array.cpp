//
//  026_Remove_Duplicates_from_Sorted_Array.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int slow = 1, fast = 1;
        for(fast = 1; fast < nums.size(); ++fast){
            if(nums[fast] != nums[fast - 1]){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = (int)nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                count++;
            }else{
                nums[i-count] = nums[i];
            }
        }
        return n-count;
    }
};
