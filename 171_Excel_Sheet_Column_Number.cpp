//
//  171_Excel_Sheet_Column_Number.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            sum = sum * 26 + (int)s[i] - 64;
        }
        return sum;
    }
};