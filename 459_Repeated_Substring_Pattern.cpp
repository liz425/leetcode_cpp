//
//  459_Repeated_Substring_Pattern.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/5/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"

class Solution4 {
    //T = O(n).
    //string.find() use a building KMP algo.
public:
    bool repeatedSubstringPattern(string str) {
        if(str.empty()){
            return false;
        }
        string ss = str + str;
        return (ss.substr(1, (int)ss.size() - 2).find(str) != -1);
    }
};


class Solution3 {
    //KMP.
    //T = O(n)
public:
    bool repeatedSubstringPattern(string str) {
        int m = (int)str.size(), k = -1;
        vector<int> next(m + 1, 0);
        next[0] = -1;
        for(int i = 1; i <= m; ++i){
            while(k >= 0 && str[k] != str[i - 1]){
                k = next[k];
            }
            next[i] = ++k;
        }
        return (next[m] != 0 && m % (m - next[m]) == 0);
    }
};


class Solution2 {
    //T = O(n^2), much more concise
public:
    bool repeatedSubstringPattern(string str) {
        int n = (int)str.size();
        for(int i = 1; i <= n / 2; ++i){
            if(n % i == 0 && str.substr(0, n - i) == str.substr(i)){
                return true;
            }
        }
        return false;
    }
};



class Solution {
    //T = O(n^2)
public:
    bool repeatedSubstringPattern(string str) {
        int n = (int)str.size();
        for(int len = 1; len <= n / 2; ++len){
            if(n % len == 0){
                int result = true;
                for(int i = 0; i < n; ++i){
                    if(str[i] != str[i % len]){
                        result = false;
                        break;
                    }
                }
                if(result){
                    return true;
                }
            }
        }
        return false;
    }
};
