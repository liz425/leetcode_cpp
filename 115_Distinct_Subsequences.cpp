//
//  115_Distinct_Subsequences.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    //1D DP
    int numDistinct(string s, string t) {
        int m = (int)s.size(), n = (int)t.size();
        if(m < n) return 0;
        vector<int> DP(m + 1, 1);
        for(int j = 1; j <= n; ++j){
            int previous = DP[j - 1];
            DP[j - 1] = 0;
            for(int i = j; i <= m; ++i){
                int current = DP[i];
                DP[i] = DP[i - 1];
                if(s[i - 1] == t[j - 1])
                    DP[i] += previous;
                previous = current;
            }
        }
        return DP[m];
    }
};


class Solution {
public:
    //2D DP
    int numDistinct(string s, string t) {
        int m = (int)s.size(), n = (int)t.size();
        if(m < n)
            return 0;
        vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
        DP[0] = vector<int>(m + 1, 1);
        for(int j = 1; j <= n; ++j){
            for(int i = j; i <= m; ++i){
                if(s[i - 1] == t[j - 1])
                    DP[j][i] += DP[j - 1][i - 1];
                DP[j][i] += DP[j][i - 1];
            }
        }
        return DP[n][m];
    }
};

