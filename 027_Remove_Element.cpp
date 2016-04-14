//
//  027_Remove_Element.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = (int)nums.size() - 1;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                while(nums[j] == val){
                    if(i >= --j){
                        return i;
                    }
                }
                swap(nums[i], nums[j]);
            }
        }
        return i;
    }
};