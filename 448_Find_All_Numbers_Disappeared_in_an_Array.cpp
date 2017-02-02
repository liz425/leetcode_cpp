//
//  448_Find_All_Numbers_Disappeared_in_an_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/28/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i){
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
