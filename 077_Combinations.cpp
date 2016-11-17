//
//  077_Combinations.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    void DFS(vector<int>& candid, int n, int k, int start, vector<vector<int>>& result){
        if(k == 0){
            result.push_back(candid);
            return;
        }
        for(int i = start; i <= n - k + 1; ++i){
            candid.push_back(i);
            DFS(candid, n, k - 1, i + 1, result);
            candid.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n == 0 || k == 0){
            return result;
        }
        vector<int> candid;
        DFS(candid, n, k, 1, result);
        return result;
    }
};
