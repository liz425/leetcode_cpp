//
//  168_Excel_Sheet_Column_Title.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    /*
    The idea is this: suppose you have excel title 52 = AZ = A * 26 + Z * 1, where A = 1, Z = 26.
    Now you shift each digit down i.e. A' = 0, and Z' = 25.
    Then 52 = AZ = (A' + 1) * 26 + (Z' + 1) * 1.
     
    So now you need to find A' and Z'. Z' = (52 - 1) % 26 = 25, which is (n-1)%26 in the code above.
    Now you need to get A' + 1 from 26 * (A' + 1) + (Z' + 1)
    If you simply do n/=26, Z' + 1 will give additional 1. So you will get n = 2 instead of n = 1.
    To avoid this you do n = (n-1)/26
     */
public :
    string convertToTitle(int n) {
        string result = "";
        while(n > 0){
            int lastDigit = (n - 1) % 26;
            result = (char)(lastDigit + 'A') + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};
