//
//  258_Add_Digits.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
class Solution {
public:
  int addDigits(int num) {
    return 1 + (num - 1)%9;
  }
};