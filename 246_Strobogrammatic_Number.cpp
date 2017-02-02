//
//  246_Strobogrammatic_Number.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/22/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.empty()){
            return true;
        }else if(isSymmetric(num[0], num[num.size() - 1])){
            if(num.size() > 2){
                return isStrobogrammatic(num.substr(1, num.size() - 2));
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
    bool isSymmetric(char a, char b){
        return (a == '0' && b == '0') || (a == '1' && b == '1') || (a == '6' && b == '9') || (a == '8' && b == '8') || (a == '9' && b == '6');
    }
};
