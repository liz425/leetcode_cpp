//
//  219_Contains_Duplicate_II.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
    //use unordered hash map
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0){
            return false;
        }
        unordered_map<int, bool> near;
        for(int i = 0; i < nums.size(); i++){
            if(near.find(nums[i]) == near.end()){
                near[nums[i]] = true;
                if(near.size() > k){
                    near.erase(nums[i - k]);
                }
            }else{
                return true;
            }
            
        }
        return false;
    }
};