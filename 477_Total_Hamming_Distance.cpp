//
//  477_Total_Hamming_Distance.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> cnt(32, 0);
        for(int num : nums){
            int shift = 0;
            while(num){
                if(num & 0x1){
                    cnt[shift]++;
                }
                shift++;
                num = num >> 1;
            }
        }
        int result = 0;
        for(int i = 0; i < 32; ++i){
            result += cnt[i] * (n - cnt[i]);
        }
        return result;
    }
};
