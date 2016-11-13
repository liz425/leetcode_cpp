//
//  076_Minimum_Window_Substring.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //T = O(n)
    //There are two ways: counter can either be various kinds of char in string_t,
    //or numbers of char in string_t which can be duplicated.
    //Here we adpot the second method
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for(char ch : t){
            hash[ch]++;
        }
        int counter = (int)t.size();
        int start = 0, end = 0;
        int minLen = INT_MAX, head = 0;
        for(end = 0; end < (int)s.size(); ++end){
            if(hash[s[end]]-- > 0)    //hash[s[end]] > 0: s[end] is part of string t
                counter--;
            while(counter == 0){        //where current window is valid
                if(end - start + 1 < minLen){
                    head = start;
                    minLen = end - start + 1;
                }
                if(hash[s[start++]]++ == 0) //after this statement, hash[s[start-1]] will be positive, so invalid again
                    counter++;
            }
        }
        if(minLen == INT_MAX)
            return "";
        else
            return s.substr(head, minLen);
    }
};
