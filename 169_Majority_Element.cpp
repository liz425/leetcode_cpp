
//
//  169_Majority_Element.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    //O(n) time, O(1) space
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int most = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                count++;
                most = nums[i];
            }else if(nums[i] == most){
                count++;
            }else{
                count--;
            }
        }
        return most;
    }
};