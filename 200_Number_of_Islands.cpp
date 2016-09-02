//
//  200_Number_of_Islands.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS, T = O(n^2)
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int result = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    result++;
                    DFS(grid, visited, m, n, i, j);
                }
            }
        }
        return result;
    }
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n, int i, int j){
        visited[i][j] = true;
        if(i > 0 && grid[i - 1][j] == '1' && !visited[i - 1][j])
            DFS(grid, visited, m, n, i - 1, j);
        if(j > 0 && grid[i][j - 1] == '1' && !visited[i][j - 1])
            DFS(grid, visited, m, n, i, j - 1);
        if(i < m - 1 && grid[i + 1][j] == '1' && !visited[i + 1][j])
            DFS(grid, visited, m, n, i + 1, j);
        if(j < n - 1 && grid[i][j + 1] == '1' && !visited[i][j + 1])
            DFS(grid, visited, m, n, i, j + 1);
    }
};