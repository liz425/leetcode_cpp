//
//  042_Trapping_Rain_Water.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int left = 0, mid = 0;
        int right = (int)height.size() - 1;
        int vol = min(height[left], height[right]);
        int sum = 0;
        //There should be no water trapped on border(left and right), so only consider mid)
        while(left + 1 < right){
            if(height[left] < height[right])
                mid = ++left;
            else
                mid = --right;
            if(height[mid] <= vol)
                sum += vol - height[mid];
            else
                vol = min(height[left], height[right]);
        }
        return sum;
    }
};
