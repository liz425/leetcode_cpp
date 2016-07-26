//
//  018_4Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/25/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
    //Time: average O(N^3), worst O(N^3).
    //run time: 20 ms
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = static_cast<int>(nums.size());
        vector<vector<int>> result;
        int i = 0;
        while(i < size - 3){
            int first = nums[i];
            int j = i + 1;
            while(j < size - 2){
                int second = nums[j];
                int k = j + 1;
                int l = size - 1;
                while(k < l){
                    int third = nums[k];
                    int fourth = nums[l];
                    //the following judgement is vital, it reduces run time from 120ms to 20ms
                    if((first + second + third * 2 > target) || (first + second + fourth * 2 < target))
                        break;
                    int sum = first + second + third + fourth;
                    if(sum == target){
                        result.push_back({first, second, third, fourth});
                    }
                    if(sum <= target){
                        while(k < l && nums[k] == third)
                            k++;
                    }
                    if(sum >= target){
                        while(k < l && nums[l] == fourth)
                            l--;
                    }
                }
                while(j < size - 2 && nums[j] == second)
                    j++;
            }
            while(i < size - 3 && nums[i] == first)
                i++;
        }
        return result;
    }
};
