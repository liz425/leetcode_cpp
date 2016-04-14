//
//  066_Plus_One.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = (int)digits.size() - 1;
        int c = 1;
        while(c == 1 && k >= 0){
            c = (1 + digits[k]) / 10;
            digits[k] = (digits[k] + 1) % 10;
            k--;
        }
        if(c == 1 && k == -1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};