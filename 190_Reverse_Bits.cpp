//
//  190_Reverse_Bits.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <cstdint>
using namespace std;

class Solution3 {
    // toggle bits when the 2 bits in a pair are different
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++)
            if ((n >> i & 1) ^ (n >> (31 - i) & 1))
                n ^= (1 << i | 1 << (31 - i));
        return n;
    }
};


class Solution2 {
    // get the i-th bit and put it to (31 - i)th bit
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for(int i = 0; i < 32; i++) {
            m = (m << 1) + (n & 1);
            n >>= 1;
        }
        return m;
    }
};


class Solution {
    // n ^= (-x ^ n) & (1 << i);  is to set the i-th bit of number n to value x
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++){
            int j = 31 - i;
            int x = (n >> i) & 1;
            int y = (n >> j) & 1;
            n ^= (-x ^ n) & (1 << j);
            n ^= (-y ^ n) & (1 << i);
        }
        return n;
    }
};