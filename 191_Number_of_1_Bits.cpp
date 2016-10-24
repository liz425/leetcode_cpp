//
//  191_Number_of_1_Bits.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //bit operation may faster than '%'
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0){
            cnt += n & 0x1;
            n = n >> 1;
        }
        return cnt;
    }
};
