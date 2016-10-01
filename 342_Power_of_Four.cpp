//
//  342_Power_of_Four.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>


class Solution {
    //bit manipulation
public:
    bool isPowerOfFour(int num) {
        return num > 0 && num == (num & 0x55555555) && !(num & (num - 1));
    }
};