//
//  008_Palindrome_Number.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    int sum = 0;
    int k = x;
    //reverse integer and compare with original integer
    //DO NOT need to worry about overflow:
    //  -- if x is palindrome, then reverse of x is itself, which will never overflow.
    //  -- if x is not palindrome and reverse of it will overflow, then reverse of x will change
    //     the sign bit, and 'sum == x' will always return false.
    while (k > 0) {
      sum = sum * 10 + k % 10;
      k /= 10;
    }
    cout << sum << endl;
    return sum == x;
  }
};