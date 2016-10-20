//
//  340_Longest_Substring_with_At_Most_K_Distinct_Characters.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k == 0)
            return 0;
        unordered_map<char, int> hash;
        int maxLen = 0;
        int left = -1, right = 0;
        int cnt = 0;
        for(right = 0; right < s.size(); ++right){
            if(hash[s[right]]++ == 0){  //adding a new char into the string, update its count in hashMap
                if(cnt < k){
                    cnt++;              //If not reach K-limit
                }else{                  //Otherwise, remove left border untill number of distinct chars decrease by 1
                    maxLen = max(maxLen, right - left - 1);     //calculate the string length before adding the new char
                    while(--hash[s[++left]] > 0);               //remove left side until one distinct removed in the substring
                }
            }
            //cout << left << " : " << right << endl;
        }
        maxLen = max(maxLen, right - left - 1); //when reach the end, calc the max again
        return maxLen;
    }
};
