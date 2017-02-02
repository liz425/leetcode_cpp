//
//  228_Summary_Ranges.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/23/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()){
            return result;
        }
        int start = nums[0];
        int end = start;
        int n = (int)nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] != nums[i - 1] + 1){
                result.push_back(getRange(start, end));
                start = end = nums[i];
            }else{
                end = nums[i];
            }
        }
        result.push_back(getRange(start, end));
        return result;
    }
    string getRange(int start, int end){
        if(start == end){
            return to_string(start);
        }else{
            return to_string(start) + "->" + to_string(end);
        }
    }
};
