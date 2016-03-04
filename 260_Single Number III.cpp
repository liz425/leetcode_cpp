//
//  260_Single Number III.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/24/16.
//  Copyright © 2016 zl. All rights reserved.
//


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int bitrecord = 0;
    for (auto& x: nums ) {
      bitrecord ^= x;
    }
    bitrecord &= (~bitrecord + 1);
    int ans1 = 0;
    int ans2 = 0;
    
    cout << bitrecord << endl;
    
    for (auto& x: nums) {
      if ((x & bitrecord) == 0) {
        ans1 ^= x;
      }else{
        ans2 ^= x;
      }
    }
    return vector<int> {ans1, ans2};
  }
};


//int main(void){
//  vector<int> input = {2,1,2,3,4,1};
//  Solution solve;
//  vector<int> output = solve.singleNumber(input);
//  cout << output[0] << " "<< output[1] << endl;
//}


