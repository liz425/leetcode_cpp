//
//  052_N-Queens_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int totalNQueens(int n) {
        int result;
        if(n == 0){
            return result;
        }
        vector<int> candid;
        unordered_set<int> col, pline, nline;
        DFS(result, col, pline, nline, 0, candid, n);
        return result;
    }
    void DFS(int& result, unordered_set<int>& col, unordered_set<int>& pline, unordered_set<int>& nline, int index, vector<int>& candid, int n){
        if(index >= n){
            if(n % 2 == 0 || candid[0] != n / 2){
                result += 2;
            }else{
                result += 1;
            }
            return;
        }
        int y = index, k;
        if(y == 0){
            k = (n + 1) / 2;
        }else{
            k = n;
        }
        for(int x = 0; x < k; ++x){
            if(col.find(x) == col.end() && pline.find(y - x) == pline.end() && nline.find(y + x) == nline.end()){
                col.insert(x);
                pline.insert(y - x);
                nline.insert(y + x);
                candid.push_back(x);
                DFS(result, col, pline, nline, index + 1, candid, n);
                col.erase(x);
                pline.erase(y - x);
                nline.erase(y + x);
                candid.pop_back();
            }
        }
        return;
    }
};
