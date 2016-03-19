//
//  53_Maximum_Subarray.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int max = nums[0];
    for(int &x: nums){
      sum += x;
      max = (sum > max)? sum : max;
      sum = (sum > 0)? sum : 0;
    }
    return max;
  }
};