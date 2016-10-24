//
//  005_Longest_Palindromic_Substring.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        string maxString = "";
        int n = (int)s.size();
        for(int i = 1; i < 2 * n; ++i){
            string candid = expand(s, (i - 1) / 2, i / 2);
            if(candid.size() > maxLen){
                maxLen = (int)candid.size();
                maxString = candid;
            }
        }
        return maxString;
    }
    string expand(string& s, int i, int j){
        while(i >= 0 && j < s.size()){
            if(s[i] == s[j]){
                i--;
                j++;
            }else{
                break;
            }
        }
        return s.substr(i + 1, j - i - 1);
    }
};
