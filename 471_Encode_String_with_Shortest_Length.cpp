//
//  471_Encode_String_with_Shortest_Length.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/6/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //recursive solution, slower than Solution1
private:
    vector<vector<string>> dp;
public:
    string encode(string s) {
        int n = (int)s.size();
        dp.assign(n, vector<string>(n, ""));
        return DFS(s, 0, n - 1);
    }
    string collapse(string s, int i, int j){
        string t = s.substr(i, j - i + 1);
        int len = (int)t.size();
        string ss = t + t;
        int pos = (int)ss.find(t, 1);
        if(pos < (int)t.size()){
            return to_string(len / pos) + '[' + DFS(s, i, i + pos - 1) + ']';
        }else{
            return s;
        }
    }
    string DFS(string s, int i, int j){
        if(i > j){
            return "";
        }else if(!dp[i][j].empty()){
            return dp[i][j];
        }
        dp[i][j] = s.substr(i, j - i + 1);
        for(int k = i; k < j; ++k){
            string first = DFS(s, i, k);
            string second = DFS(s, k + 1, j);
            if(dp[i][j].size() > first.size() + second.size()){
                dp[i][j] = first + second;
            }
        }
        string col = collapse(s, i, j);
        if(col.size() < dp[i][j].size()){
            dp[i][j] = col;
        }
        return dp[i][j];
    }
};



class Solution {
private:
    vector<vector<string>> dp;
public:
    string collapse(string& s, int i, int j){
        string t = s.substr(i, j - i + 1);
        int len = (int)t.size();
        string ss = t + t;
        auto pos = ss.find(t, 1);
        if(pos < t.size()){
            return to_string(len / pos) + '[' + dp[i][i + pos - 1] + ']';
        }else{
            return s;
        }
    }
    string encode(string s) {
        int n = (int)s.size();
        if(n == 0){
            return "";
        }
        dp.assign(n, vector<string>(n, ""));
        for(int step = 1; step <= n; step++){
            for(int i = 0; i + step <= n; ++i){
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);
                for(int k = i; k < j; ++k){
                    if(dp[i][j].size() > dp[i][k].size() + dp[k + 1][j].size()){
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
                string col = collapse(s, i, j);
                if(col.size() < dp[i][j].size()){
                    dp[i][j] = col;
                }
            }
        }
        return dp[0][n - 1];
    }
};
