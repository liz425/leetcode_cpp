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
        int i = 0, j = (int)height.size() - 1;
        int sum = 0, vol = min(height[i], height[j]);
        while(i < j - 1){
            int mid;
            if(height[i] < height[j]){
                mid = ++i;
            }else{
                mid = --j;
            }
            if(height[mid] <= vol)
                sum += vol - height[mid];
            else
                vol = min(height[i], height[j]);
        }
        return sum;
    }
};
