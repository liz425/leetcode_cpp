//
//  003_Longest_Substring_Without_Repeating_Characters.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //two pointers. hash[chr] stores the most recent position char appears in the string, indexed from 1
    //once found old already stay in substring and index > start, update start.
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        if(s.empty()){
            return 0;
        }
        int start = 1, end = 1;
        hash[s[0]] = 1;
        int maxLen = 1;
        for(int i = 1; i < s.size(); ++i){
            end = i + 1;
            if(hash[s[i]] >= start)
                start = hash[s[i]] + 1;
            hash[s[i]] = end;
            maxLen = max(maxLen, end - start + 1);
            //cout << maxLen << endl;
        }
        return maxLen;
    }
};
