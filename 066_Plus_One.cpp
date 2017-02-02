//
//  066_Plus_One.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Do not modify original digits
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        int carry = 1;
        for(auto it = result.rbegin(); it != result.rend() && carry != 0; it++){
            int sum = *it + carry;
            *it = (sum % 10);
            carry = sum / 10;
        }
        if(carry){
            result.insert(result.begin(), carry);
        }
        return result;
    }
};


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
