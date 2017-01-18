//
//  279_Perfect_Squares.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/7/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"



class Solution3 {
    //Static DP
private:
    static vector<int> dp;
    static int size;
public:
    int numSquares(int n) {
        if(n <= size){
            return dp[n];
        }
        for(int i = size + 1; i <= n; ++i){
            dp.push_back(INT_MAX);
            if(pow((int)sqrt(i), 2) == i){
                dp[i] = 1;
            }else{
                for(int j = 1; j * j < i; ++j){
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
            //cout << dp[i] << endl;
        }
        size = n;
        return dp[n];
    }
};
vector<int> Solution3::dp = vector<int>(1, 0);
int Solution3::size = 0;




class Solution2 {
    //DP
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i <= n; ++i){
            if(pow((int)sqrt(i), 2) == i){
                dp[i] = 1;
            }else{
                for(int j = 1; j * j < i; ++j){
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
            //cout << dp[i] << endl;
        }
        return dp[n];
    }
};


class Solution {
    //DFS
private:
    int result = INT_MAX;
public:
    int numSquares(int n) {
        DFS(n, (int)sqrt(n), 0);
        return result;
    }
    void DFS(int n, int start, int cnt){
        if(cnt > result){
            return;
        }
        if(n == 0){
            result = min(result, cnt);
        }
        start = min(start, (int)sqrt(n));
        for(int i = start; i >= 1; --i){
            DFS(n - i * i, i, cnt + 1);
        }
    }
};
