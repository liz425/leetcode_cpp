//
//  032_Longest_Valid_Parentheses.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        int size = (int)s.size();
        vector<int> DP(size + 1, 0);
        int left = 0;
        int longest = 0;
        for(int i = 0; i < size; ++i){
            if(s[i] == '('){
                left++;
            }else if(s[i] == ')' && left > 0){
                DP[i + 1] = DP[i] + 2;
                DP[i + 1] += DP[i + 1 - DP[i + 1]];
                left--;
            }
            longest = max(longest, DP[i + 1]);
        }
        return longest;
    }
};
