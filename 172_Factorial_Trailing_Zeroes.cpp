//
//  172_Factorial_Trailing_Zeroes.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n > 0){
            n /= 5;
            sum += n;
        }
        return sum;
    }
};