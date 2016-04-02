//
//  283_Move_Zeroes.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] != 0){
                int swap = nums[i];
                nums[i] = nums[left];
                nums[left++] = swap;
            }
        }
    }
};