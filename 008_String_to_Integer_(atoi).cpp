//
//  008_String_to_Integer_(atoi).cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    int myAtoi(string str) {
        long sum = 0;
        bool leading = true;
        int len = (int)str.length();
        int sign = 1;
        for(int i = 0; i < len; i++){
            if(str[i] >= '0' && str[i] <= '9'){
                sum = sum * 10 + (str[i] - '0') * sign;
                if(sum > INT_MAX){
                    return INT_MAX;
                }else if(sum < INT_MIN){
                    return INT_MIN;
                }
                leading = false;
            }else if(leading && str[i] == '+'){
                leading = false;
            }
            else if(leading && str[i] == '-'){
                sign = -1;
                leading = false;
            }else if(leading && str[i] == ' '){
                continue;
            }else{
                break;
            }
        }
        return (int)sum;
    }
};
