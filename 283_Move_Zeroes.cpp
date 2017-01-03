//
//  283_Move_Zeroes.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //minimized operations to vector nums[]
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int)nums.size();
        int left = 0;
        for(int right = 0; right < n; ++right){
            if(nums[right] != 0){
                if(right != left){
                    swap(nums[left++], nums[right]);
                }else{
                    left++;
                }
            }
        }
    }
};



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                swap(nums[i], nums[left]);
                left++;
            }
        }
        return;
    }
};
