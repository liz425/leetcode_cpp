//
//  010_Regular_Expression_Matching.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

//////////////////////////////////////////////////
// This code seems right when running on my machine
// But it encounter "Runtime Error" in the leetcode
// Have no idea why it happens.
//////////////////////////////////////////////////


#include "inc.h"

class Solution2 {
    //DP solution, should use this.
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size(), n = (int)p.size();
        vector<vector<bool>> DP(m + 1, vector<bool>(n + 1, false));
        DP[0][0] = true;
        for(int i = 1; i <= m; ++i){
            DP[i][0] = false;
        }
        for(int i = 1; i <= n; ++i){
            DP[0][i] = i > 1 && p[i - 1] == '*' && DP[0][i - 2];
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j - 1] == '*'){
                    DP[i][j] = j > 1 && (DP[i][j - 2] || (DP[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])));
                }else{
                    DP[i][j] = DP[i - 1][j - 1] && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                }
            }
        }
        return DP[m][n];
    }
};


class Solution1 {
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


class Solution {
//Non-DP solution. Compare backward (from back to front)
//Really SLOW. Should NEVER use it.
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
    
        if(p.back() == '*'){
            string p1 = p;
            p1.pop_back();
            if(p1.empty())
                return false;
            char c_p = p1.back();
            p1.pop_back();
      
            if(isMatch(s, p1))
                return true;
            else if(!s.empty()){
                string s1 = s;
                char c_s = s1.back();
                s1.pop_back();
                
                if(!CharEqual(c_p, c_s))
                    return false;
                else if(isMatch(s1, p1))
                    return true;
                else
                    return isMatch(s1, p);
                }
            else
                return false;
        }else if(s.empty()){
            return false;
        }else if (CharEqual(s.back(), p.back())) {
            s.pop_back();
            p.pop_back();
            return isMatch(s, p);
        }else{
            return false;
        }
    }
  
    bool CharEqual(char a, char b){
        return (a == '.' || b == '.' || a == b);
    }
};

/*
int main(){
    Solution2 ss;
    cout << ss.isMatch("aa", "a*") << endl;
    return 0;
}
*/