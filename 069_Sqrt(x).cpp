//
//  069_Sqrt(x).cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Binary search. Key point: multiplication may cause overflow!!
public:
    int mySqrt(int x) {
        int i = 0, j = x;
        while(i < j - 1){
            int mid = i + (j - i) / 2;
            if(long(mid) * long(mid) <= x){
                i = mid;
            }else{
                j = mid;
            }
        }
        if(long(j) * long(j) > x)
            return i;
        else
            return j;
    }
};
