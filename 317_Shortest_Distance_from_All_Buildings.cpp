//
//  317_Shortest_Distance_from_All_Buildings.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    void BFS(vector<vector<int>>& grid, queue<pair<int, int>> fringe, vector<vector<bool>> visited, vector<vector<int>>& cnt, vector<vector<int>>& dist){
        int level = 0;
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        while(!fringe.empty()){
            int size = (int)fringe.size();
            for(int i = 0; i < size; ++i){
                auto cur = fringe.front();
                fringe.pop();
                int p = cur.first;
                int q = cur.second;
                dist[p][q] += level;
                cnt[p][q]++;
                if(p > 0 && grid[p - 1][q] == 0 && !visited[p - 1][q]){
                    fringe.push(make_pair(p - 1, q));
                    visited[p - 1][q] = true;
                }
                if(p < m - 1 && grid[p + 1][q] == 0 && !visited[p + 1][q]){
                    fringe.push(make_pair(p + 1, q));
                    visited[p + 1][q] = true;
                }
                if(q > 0 && grid[p][q - 1] == 0 && !visited[p][q - 1]){
                    fringe.push(make_pair(p, q - 1));
                    visited[p][q - 1] = true;
                }
                if(q < n - 1 && grid[p][q + 1] == 0 && !visited[p][q + 1]){
                    fringe.push(make_pair(p, q + 1));
                    visited[p][q + 1] = true;
                }
            }
            level++;
        }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return -1;
        }
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int buildCnt = 0;
        int minDist = INT_MAX;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    buildCnt++;
                    queue<pair<int, int>> fringe;
                    fringe.push(make_pair(i, j));
                    BFS(grid, fringe, visited, cnt, dist);
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0 && cnt[i][j] == buildCnt)
                    minDist = min(minDist, dist[i][j]);
            }
        }
        return (minDist == INT_MAX)? -1 : minDist;
    }
};


/*
int main(void){
    Solution ss;
    vector<vector<int>> grid{{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout << ss.shortestDistance(grid) << endl;
}
*/
