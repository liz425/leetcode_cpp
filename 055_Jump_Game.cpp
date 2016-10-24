//
//  055_Jump_Game.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Same idea of DP, but all previous states can be stored in maxIndex
    //T = O(n), Space = O(1);
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return true;
        int maxIndex = 0;    //current max index can reach
        int target = (int)nums.size() - 1;
        for(int i = 0; i <= target; ++i){
            if(maxIndex < i){   //can't reach index-i
                return false;
            }else{              //can reach index-i, update maxIndex
                maxIndex = max(maxIndex, i + nums[i]);
            }
        }
        return true;
    }
};
