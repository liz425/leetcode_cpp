//
//  043_Multiply_Strings.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = (int)num1.size();
        int len2 = (int)num2.size();
        vector<int> products(len1 + len2, 0);
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                products[i + j] += int(num1[i] - '0') * int(num2[j] - '0'); //add
                products[i + j + 1] += products[i + j] / 10;    //carry
                products[i + j] = products[i + j] % 10;         //remain
            }
        }
        
        int i;
        //remove leading zeros, but keep the last one digit
        for(i = len1 + len2 - 1; i > 0 && products[i] == 0; --i);
        string result = "";
        for(; i >= 0; --i){
            result += char(products[i] + '0');
        }
        return result;
    }
};
