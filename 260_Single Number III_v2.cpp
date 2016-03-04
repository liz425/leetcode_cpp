//
//  260_Single Number III.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/24/16.
//  Copyright © 2016 zl. All rights reserved.
//


#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, bool> hashtable;
    for (int i = 0; i < nums.size(); i++) {
      if(!hashtable[nums[i]]){
        hashtable[nums[i]] = true;
      }else{
        hashtable.erase(nums[i]);
      }
    }
    vector<int> ans;
   
    for(auto& x: hashtable){
      ans.push_back(x.first);
    }
    return ans;
  }
};