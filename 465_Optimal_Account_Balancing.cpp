//
//  465_Optimal_Account_Balancing.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    int minTran = INT_MAX;
public:
    void DFS(vector<int>& accounts, int n, int start, int trans){
        if(trans > minTran){
            return;
        }
        while(start < n && accounts[start] == 0){
            start++;
        }
        if(start >= n){
            minTran = min(minTran, trans);
        }
        for(int i = start + 1; i < (int)accounts.size(); ++i){
            if(long(accounts[i]) * long(accounts[start]) < 0){
                accounts[i] += accounts[start];
                DFS(accounts, n, start + 1, trans + 1);
                accounts[i] -= accounts[start];
            }
        }
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> money;
        for(auto tran : transactions){
            money[tran[0]] += tran[2];
            money[tran[1]] -= tran[2];
        }
        vector<int> accounts;
        for(auto m : money){
            if(m.second != 0){
                accounts.push_back(m.second);
            }
        }
        DFS(accounts, (int)accounts.size(), 0, 0);
        return minTran;
    }
};
