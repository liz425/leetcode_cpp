//
//  051_N-Queens.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //only DFS the left half of the first row. Then mirror and double the answer.
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n == 0){
            return result;
        }
        vector<int> candid;
        unordered_set<int> col, pline, nline;
        DFS(result, col, pline, nline, 0, candid, n);
        return result;
    }
    void DFS(vector<vector<string>>& result, unordered_set<int>& col, unordered_set<int>& pline, unordered_set<int>& nline, int index, vector<int>& candid, int n){
        if(index >= n){
            result.push_back(generateBoard(n, candid));
            if(n % 2 == 0 || candid[0] != n / 2){
                vector<int> mirror;
                for(int i : candid){
                    mirror.push_back(n - 1 - i);
                }
                result.push_back(generateBoard(n, mirror));
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
    vector<string> generateBoard(int n, vector<int>& candid){
        vector<string> result;
        for(int i = 0; i < n; ++i){
            result.push_back(string(candid[i], '.') + 'Q' + string(n - candid[i] - 1, '.'));
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n == 0){
            return result;
        }
        vector<int> candid;
        unordered_set<int> col, pline, nline;
        DFS(result, col, pline, nline, 0, candid, n);
        return result;
    }
    void DFS(vector<vector<string>>& result, unordered_set<int>& col, unordered_set<int>& pline, unordered_set<int>& nline, int index, vector<int>& candid, int n){
        if(index >= n){
            result.push_back(generateBoard(n, candid));
            return;
        }
        int y = index;
        for(int x = 0; x < n; ++x){
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
    vector<string> generateBoard(int n, vector<int>& candid){
        vector<string> result;
        for(int i = 0; i < n; ++i){
            result.push_back(string(candid[i], '.') + 'Q' + string(n - candid[i] - 1, '.'));
        }
        return result;
    }
};


/*
int main(void){
    Solution2 ss;
    cout << ss.solveNQueens(5).size() << endl;
}
*/
