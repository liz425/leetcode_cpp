//
//  132_Palindrome_Partitioning_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/10/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //Another observation:
    //[j, i] is palindrome, only if [j + 1, i - 1] is palindrome and s[j] == s[i]
    //Faster than Solution2
public:
    int minCut(string s) {
        int n = (int)s.size();
        vector<vector<bool>> isPanlin(n, vector<bool>(n, false));
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(s[j] == s[i] && (j + 1 > i - 1 || isPanlin[j + 1][i - 1])){
                    isPanlin[j][i] = true;
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[n] - 1;
    }
};


class Solution2 {
    //One observation: dp[i] is the min of cut[j - 1] + 1, for all j that [j, i] is palindrome
    //Pass the test, slower than Solution3
public:
    int minCut(string s) {
        int n = (int)s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                if(dp[j - 1] + 1 < dp[i] && isPalindrome(s, j - 1, i - 1)){
                    //key step: first check whether dp[j - 1] + 1 < dp[i].
                    //If not, no need to
                    dp[i] = dp[j - 1] + 1;
                }
            }
        }
        return dp[n] - 1;
    }
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};


class Solution {
    //TLE. No need to use 2-D dp
public:
    int minCut(string s) {
        int n = (int)s.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for(int step = 1; step <= n; ++step){
            for(int i = 0; i <= n - step; ++i){
                if(isPalindrome(s, i, i + step - 1)){
                    dp[i][i + step - 1] = 1;
                }else{
                    for(int j = 1; j < step; ++j){
                        dp[i][i + step - 1] = min(dp[i][i + step - 1], dp[i][i + j - 1] + dp[i + j][i + step - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1] - 1;
    }
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};


/*
int main(void){
    Solution3 ss;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << ss.minCut(s) << endl;
}
*/
