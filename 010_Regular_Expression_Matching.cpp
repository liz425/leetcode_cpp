//
//  010_Regular_Expression_Matching.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/21/16.
//  Copyright © 2016 zl. All rights reserved.
//



#include "inc.h"


class Solution3 {
    //DP, based on Solution2. Use rolling array to reduce memory space consumption.
    //Moreover, "% 3" can be changed to "% 2" for futher optimization here.
    //If only we are not going to use dp[(i - 2) % 2][j - x] (x > 0) when calculating dp[i][j],
    //We are safe to overwrite dp[(i - 2) % 2][j]. Because dp[(i - 2) % 2][j - x] is already overwritten at j-th loop.
    //In this solution, we are safe. However, "% 3" is always safe with little overhead.
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size();
        int n = (int)p.size();
        vector<vector<bool>> dp(3, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i){
            dp[i % 3][0] = (i > 1) && (p[(i - 1)] == '*') && dp[(i - 2) % 3][0];
            for(int j = 1; j <= m; ++j){
                if(p[(i - 1)] == '*'){
                    dp[i % 3][j] = (i > 1) && (dp[(i - 2) % 3][j] || (dp[i % 3][j - 1]  && (p[i - 2] == '.' || p[i - 2] == s[j - 1])));
                }else{
                    dp[i % 3][j] = dp[(i - 1) % 3][j - 1] && (p[i - 1] == '.' || p[i - 1] == s[j - 1]);
                }
            }
        }
        return dp[n % 3][m];
    }
};



class Solution2 {
    //DP solution
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size();
        int n = (int)p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = (i > 1) && (p[i - 1] == '*') && dp[i - 2][0];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(p[i - 1] == '*'){
                    dp[i][j] = (i > 1) && (dp[i - 2][j] || (dp[i][j - 1]  && (p[i - 2] == '.' || p[i - 2] == s[j - 1])));
                }else{
                    dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == '.' || p[i - 1] == s[j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};


class Solution {
//Non-DP, compare forward, from head to tail
//Really SLOW, Never use it.
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};


/*
int main(){
    Solution2 ss;
    cout << ss.isMatch("aa", "a*") << endl;
    return 0;
}
*/
