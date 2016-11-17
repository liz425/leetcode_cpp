//
//  050_Pow(x, n).cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }else if(n < 0){
            //In case of n = INT_MIN, then -n will overflow, shoudld first add 1 to n
            //Assume that the input is legal: x will not be equal to 0 when n < 0
            return 1 / x * myPow(1 / x, -(n + 1));
        }else if(n % 2 == 0){
            return myPow(x * x, n / 2);
        }else{
            return myPow(x * x, n / 2) * x;
        }
    }
};
