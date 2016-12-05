//
//  329_Longest_Increasing_Path_in_a_Matrix.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS + memorize search, T = O(m * n), m: number of rows, n: number of columns
private:
    vector<vector<int>> lip;
    vector<vector<bool>> visited;
    vector<int> delta;
public:
    int DFS(vector<vector<int>>& matrix, int m, int n, int p, int q){
        if(lip[p][q] != 0){
            return lip[p][q];
        }
        int maxLen = 1;
        for(int i = 0; i < 4; ++i){
            int x = p + delta[i];
            int y = q + delta[i + 1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[p][q]){
                maxLen = max(maxLen, 1 + DFS(matrix, m, n, x, y));
            }
        }
        lip[p][q] = maxLen;
        return maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        lip = vector<vector<int>>(m, vector<int>(n, 0));
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        delta = {1, 0, -1, 0, 1};
        int result = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                result = max(result, DFS(matrix, m, n, i, j));
            }
        }
        return result;
    }
};
