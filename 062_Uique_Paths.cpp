//
//  062_Uique_Paths.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    int uniquePaths(int m, int n) {
        long rtn = 1;
        if(m > n){
            int tmp = m;
            m = n;
            n = tmp;
        }
        for(int i = 1; i <= m - 1; i++){
            rtn = rtn * (n - 1 + i) / (i);
        }
        return (int)rtn;
    }
};