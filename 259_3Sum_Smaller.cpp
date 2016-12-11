//
//  259_3Sum_Smaller.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/9/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
    //same idea, slightly change 
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 2; ++i){
            int j = i + 1;
            int k = n - 1;
            int remain = target - nums[i];
            while(j < k){
                while(j < k && nums[j] + nums[k] >= remain){
                    k--;
                }
                cnt += k - j;
                j++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = int(nums.size());
        int cnt = 0;
        for(int i = 0; i < size - 2; ++i){
            int remain = target - nums[i];
            int j = i + 1, k = size - 1;
            while(j < k){
                if(nums[j] + nums[k] < remain){
                    cnt += k - j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return cnt;
    }
};
