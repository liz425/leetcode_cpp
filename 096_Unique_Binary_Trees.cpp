//
//  96_Unique_Binary_Trees.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> bts (n + 1);
    bts[0] = 1;
    for(int i = 1; i <= n; i++){
      bts[i] = 0;
      for(int j = 0; j < i; j++){
        bts[i] += bts[j] * bts[i-j-1];
      }
    }
    return bts[n];
  }
};