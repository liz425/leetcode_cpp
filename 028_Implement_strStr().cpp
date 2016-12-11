//
//  028_Implement_strStr().cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
    //KMP, T = O(m + n), n = len_of_haystack, m = len_of_needle
    vector<int> getNext(string P){
        int m = (int)P.size();
        vector<int> next(m + 1, 0);
        next[0] = -1;
        int k = -1;
        for(int i = 1; i <= m; ++i){
            while(k >= 0 && P[k] != P[i - 1]){
                k = next[k];
            }
            next[i] = ++k;
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        vector<int> next = getNext(needle);
        int k = 0;
        int m = (int)needle.size();
        int n = (int)haystack.size();
        for(int i = 1; i <= n; ++i){
            while(k >= 0 && needle[k] != haystack[i - 1]){
                k = next[k];
            }
            k++;
            if(k == m){
                return i - m;
            }
        }
        return -1;
    }
};


class Solution {
    //Brutal force, T = O(m*n), n = len_of_haystack, m = len_of_needle
public:
    int strStr(string haystack, string needle) {
        int n = (int)haystack.length();
        int m = (int)needle.length();
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            for (j = 0; j < m; j++){
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};




