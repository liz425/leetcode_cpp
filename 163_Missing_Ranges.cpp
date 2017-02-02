//
//  163_Missing_Ranges.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/21/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    // T = O(n), n = nums.size()
    //Notice that we should solve situation such as INT_MIN and INT_MAX.
    //Key to this solution is to use a long int 'lower_long' to represent the lower bound to avoid overflow.
    //And each time we meet some num in nums, getRange() and then update the lower_long
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        long lower_long = lower;
        //In each loop, [lower_long, upper] is always the range to be dealt with.
        for(int num : nums){
            if(num < lower_long){
                continue;
            }else if(num <= upper){
                if(lower_long < num){
                    result.push_back(getRange(int(lower_long), num - 1));
                }
                lower_long = long(num) + 1;
            }else{
                break;
            }
        }
        if(lower_long <= upper){
            result.push_back(getRange(int(lower_long), upper));
        }
        return result;
    }
    //[start, end] should be the range
    string getRange(int start, int end){
        if(start == end){
            return to_string(start);
        }else{
            return to_string(start) + "->" + to_string(end);
        }
    }
};
