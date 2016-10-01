//
//  179_Largest_Number.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        auto cmp = [](string& s1, string& s2){
            return (s1+s2 > s2+s1);
        };
        vector<string> numStrings;
        for(auto& num : nums){
            numStrings.push_back(to_string(num));
        }
        sort(numStrings.begin(), numStrings.end(), cmp);
        string result;
        for(auto& str : numStrings){
            result += str;
        }
        return (result[0] == '0')? "0" : result;
    }
};