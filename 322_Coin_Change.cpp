//
//  322_Coin_Change.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //Use this one
    //DP, faster in C++
    //But theoritically, BFS should run faster than DP
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for(auto& coin : coins){
            for(int i = coin; i <= amount; ++i){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return (dp[amount] == INT_MAX - 1)? -1 : dp[amount];
    }
    
};


class Solution2 {
    //BFS, change queue to malloc array
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int *boundry = (int*)calloc(4, amount + 1);
        boundry = (int*) boundry;
        int boundryCnt = 0;
        boundry[boundryCnt++] = 0;
        
        int *newBoundry = (int*)calloc(4, amount + 1);
        int newBoundryCnt = 0;
        vector<bool> visited(amount + 1, false);
        visited[0] = true;
        int cnt = 0;
        while(boundryCnt != 0){
            cnt++;
            for(int i = 0; i < boundryCnt; ++i){
                int val = boundry[i];
                for(auto& coin : coins){
                    int newVal = val + coin;
                    if(newVal <= amount){
                        if(!visited[newVal]){
                            if(newVal == amount){
                                free(boundry);
                                free(newBoundry);
                                return cnt;
                            }
                            newBoundry[newBoundryCnt++] = newVal;
                            visited[newVal] = true;
                        }
                    }
                }
            }
            swap(boundry, newBoundry);
            boundryCnt = newBoundryCnt;
            newBoundryCnt = 0;
        }
        free(boundry);
        free(newBoundry);
        return -1;
    }
};



class Solution {
    //BFS, use queue
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        queue<int> boundry;
        boundry.push(0);
        vector<bool> visited(amount + 1, false);
        visited[0] = true;
        int cnt = 0;
        while(!boundry.empty()){
            cnt++;
            int size = (int)boundry.size();
            for(int i = 0; i < size; ++i){
                int val = boundry.front();
                boundry.pop();
                for(auto& coin : coins){
                    int newVal = val + coin;
                    if(newVal <= amount){
                        if(!visited[newVal]){
                            if(newVal == amount){
                                return cnt;
                            }
                            boundry.push(newVal);
                            visited[newVal] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

/*
int main(){
    Solution3 ss;
    vector<int> coins = {139,442,147,461,244,225,28,378,371};
    int amount = 9914;
    
    clock_t start, end;
    start = clock();
    int result = ss.coinChange(coins, amount);
    end = clock();
    cout << "result: " << result << endl;
    double time_consumed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "time: " << time_consumed << endl;
    return 0;
}
*/
