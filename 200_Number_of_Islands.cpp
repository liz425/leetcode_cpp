//
//  200_Number_of_Islands.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //DFS, T = O(n^2)
    //DFS is better than Union-find. But DFS can't deal with 305_Number_of_Islands_II
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


class Solution1 {
    //Union-find, T = O(n^2)
    //Union and find operation take amortized O(1) time.
public:
    vector<int> father;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; ++j){
                int parent = (grid[i][j] == '1')? i*n+j : -1;
                father.push_back(parent);
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i < m - 1 && father[i*n+j] >= 0 && father[(i+1)*n+j] >= 0)
                    un(i*n+j, (i+1)*n+j);
                if(j < n - 1 && father[i*n+j] >= 0 && father[i*n+j+1] >= 0)
                    un(i*n+j, i*n+j+1);
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(father[i*n+j] == i*n+j)
                    cnt++;
            }
        }
        return cnt;
    }
    int compressed_find(int k){
        int son = k;
        while(father[son] != son){
            son = father[son];
        }
        int ancestor = son;
        son = k;
        while(father[son] != son){
            int parent = father[son];
            father[son] = ancestor;
            son = parent;
        }
        return ancestor;
    }
    
    //union is a reserved type in c++
    void un(int p, int q){
        int father_p = compressed_find(p);
        int father_q = compressed_find(q);
        if(father_p != father_q)
            father[father_p] = father_q;
    }
};


