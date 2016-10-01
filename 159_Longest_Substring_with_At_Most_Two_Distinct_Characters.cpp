//
//  159_Longest_Substring_with_At_Most_Two_Distinct_Characters.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //hash table, two pointers
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> hash;
        if(s.empty()){
            return 0;
        }
        int start = 0, end = 0;
        hash[s[start]] = 1;
        int maxLen = 1;
        int cnt = 1;
        for(end = 1; end < s.size(); ++end){
            hash[s[end]]++;
            if(hash[s[end]] == 1 && cnt == 1)
                cnt++;
            else if(hash[s[end]] == 1 && cnt >= 2){
                while(start <= end){
                    hash[s[start]]--;
                    start++;
                    if(hash[s[start - 1]] == 0)
                        break;
                }
            }
            maxLen = max(maxLen, end - start + 1);
            //cout << maxLen << endl;
        }
        return maxLen;
    }
};
