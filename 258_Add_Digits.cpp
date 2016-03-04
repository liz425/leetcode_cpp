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
    while(num > 0){
      if(num < 10){
        return num;
      }else{
        int sum = 0;
        while(num > 0){
          sum += num % 10;
          num /= 10;
        }
        num = sum;
      }
    }
    return num;
  }
};