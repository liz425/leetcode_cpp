//
//  338_Counting_Bits.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    vector<int> countBits(int num) {
        //one pass
        vector<int> result;
        result.push_back(0);
        int power = 1;
        int cnt = 0;
        for(int i = 1; i <= num; ++i){
            if(i >= power){
                power *= 2;
                cnt = 0;
            }
            result.push_back(result[cnt++] + 1);
        }
        return result;
    }
};
