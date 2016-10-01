//
//  368_Largest_Divisible_Subset.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/5/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> result;
        if(size == 0){
            return result;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> cnt(size, 0);
        vector<int> pre(size, -1);
        int max = 0;
        for(int i = 0; i < size - 1; ++i){
            for(int j = i + 1; j < size; ++j){
                if(nums[i] % nums[j] == 0){
                    if(cnt[j] < cnt[i] + 1){
                        pre[j] = i;
                        cnt[j] = cnt[i] + 1;
                        if(cnt[j] > cnt[max]){
                            max = j;
                        }
                    }
                }
            }
        }
        while(max >= 0){
            result.push_back(nums[max]);
            max = pre[max];
        }
        return result;
    }
};