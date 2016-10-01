//
//  044_Wildcard_Matching.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //Brilliant solution from: http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
    //runtime 12 ms
public:
    bool isMatch(string s, string p) {
        int m = (int)s.length(), n = (int)p.length();
        int i = 0, j = 0, asterisk = -1, match = 0;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterisk = j++;
            }else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }else
                return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};


class Solution2 {
    //backtracing, EVEN SLOWER than Solution1
    //runtime: TLE
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        else{
            if(p[0] == '*'){
                //remove duplicated '*'
                int k = 1;
                while(k < p.size() && p[k] == '*')
                    k++;
                for(int i = 0; i <= s.size(); ++i){
                    if(isMatch(s.substr(i), p.substr(k)))
                        return true;
                }
                return false;
            }else{
                if(s.empty() || (p[0] != '?' && s[0] != p[0]))
                    return false;
                else{
                    return isMatch(s.substr(1), p.substr(1));
                }
            }
        }
    }
};


class Solution {
    //DP, works but super SLOW
    //runtime: 1364 ms
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(char c : p){
            bool pre = dp[0];
            if(c != '*'){
                dp[0] = false;
            }
            for(int i = 1; i <= s.size(); ++i){
                bool preTmp = dp[i];
                if(c == '*'){
                    dp[i] = dp[i - 1] || dp[i]; //dp[i]: match empty;  dp[i-1]: match one more character
                }else if(c == '?'){
                    dp[i] = pre;
                }else{
                    dp[i] = pre && (c == s[i - 1]);
                }
                pre = preTmp;
            }
        }
        return dp[s.size()];
    }
};

/*
int main(){
    Solution3 ss;
    cout << ss.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
}
*/