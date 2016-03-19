//
//  35_Search_Insert_Position.cpp
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
  int searchInsert(vector<int>& nums, int target) {
    int front = 0;
    int end = (int)nums.size() - 1;
    int middle = (front + end) / 2;
    while(front <= end){
      if(nums[middle] == target){
        return middle;
      }
      if(target < nums[middle]){
        end = middle - 1;
      }else{
        front = middle + 1;
      }
      middle = (front + end)/2;
    }
    return front;
  }
};