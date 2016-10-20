//
//  268_Missing_Number.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Bit operation, T = O(n), best solution
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int XORValue = n;
        for(int i = 0; i < n; i++){
            XORValue ^= (nums[i] ^ i);
        }
        return XORValue;
    }
};


class Solution {
    //Sum, should take care of overflow
    //O(n)
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        int n = (int)nums.size();
        return (1 + n)*n/2 - sum;
    }
};
