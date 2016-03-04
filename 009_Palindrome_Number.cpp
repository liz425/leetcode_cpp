//
//  008_Palindrome_Number.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <cmath>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int k = (int)log10(x);
    int i = 0;
    while (i <= k/2) {
      if (x/(int)pow(10, i)%10 != x/(int)pow(10, k - i)%10) {
        return false;
      }
      else
        i++;
    }
    return true;
  }
};