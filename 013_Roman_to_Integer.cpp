//
//  13_Roman_to_Integer.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int flag = 1;
        int prev = 0;
        int current = 0;
        for(int i = (int)s.length() - 1; i >= 0; i--){
            switch (s[i]){
                case 'I': current = 1; break;
                case 'V': current = 5; break;
                case 'X': current = 10; break;
                case 'L': current = 50; break;
                case 'C': current = 100; break;
                case 'D': current = 500; break;
                case 'M': current = 1000; break;
            }
            flag = (current > prev)? 1 : (current < prev)? -1 : flag;
            sum += flag * current;
            prev = current;
        }
        return sum;
    }
};