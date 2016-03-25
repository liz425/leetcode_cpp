//
//  075_Sort_Colors.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1;
        int right = (int)nums.size();
        int i = 0;
        while(i < right){
            if(nums[i] == 0){
                swap(nums[++left], nums[i++]);
            }else if(nums[i] == 1){
                i++;
            }else{
                swap(nums[--right], nums[i]);
            }
        }
    }
};
