//
//  007_Reverse_Integer.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
  int reverse(int x) {
    //in case that input '-x' overflow, check input
    if (x == 0x80000000) {
      return 0;
    }
    
    if (x < 0) {
      return -(this->reverse(-x));
    }
    long sum = 0;
    while (x > 0) {
      sum = sum * 10 + x % 10;
      //Use long_int type to stored reversed int, then check whether overflow
      if (sum > 0x7fffffff) {
        return 0;
      }
      x /= 10;
    }
    return (int)sum;
  }
};