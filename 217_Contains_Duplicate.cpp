//
//  217_Contains_Duplicate.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> nonDulp (nums.begin(), nums.end());
        return nums.size() > nonDulp.size();
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dulp;
        for(int i = 0; i < (int)nums.size(); i++){
            if(dulp[nums[i]] == 1){
                return true;
            }else{
                dulp[nums[i]] = 1;
            }
        }
        return false;
    }
};