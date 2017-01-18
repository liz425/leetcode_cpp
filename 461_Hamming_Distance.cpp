//
//  461_Hamming_Distance.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x ^ y;
        int cnt = 0;
        while(result){
            if(result & 0x1){
                cnt++;
            }
            result = result >> 1;
        }
        return cnt;
    }
};
