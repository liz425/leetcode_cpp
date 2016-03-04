//
//  006_ZigZag_Conversion.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string ans = "";
    int len = (int)s.length();
    for (int i = 1; i <= numRows ; i++) {
      if (i == 1 || i == numRows) {
        int index = i;
        while (index <= len) {
          ans += s[index - 1];
          index += 2*numRows - 2;
        }
      }
      else{
        int index = i;
        while (index <= len) {
          ans += s[index - 1];
          if (index + 2*(numRows - i) <= len) {
            ans += s[index + 2*(numRows - i) - 1];
          }
          index += 2*numRows - 2;
        }
      }
    }
    return ans;
  }
};