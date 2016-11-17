//
//  317_Shortest_Distance_from_All_Buildings.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
    //Stefan's code and his explanation:
    //I think mine is faster because I don't use a fresh "visited" for each BFS. Instead, I walk only onto the cells that were
    //reachable from all previous buildings. From the first building I only walk onto cells where grid is 0, and make them -1.
    //From the second building I only walk onto cells where grid is -1, and I make them -2. And so on.
public:
    int shortestDistance(vector<vector<int>> grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        auto total = grid;
        int walk = 0, mindist = -1, delta[] = {0, 1, 0, -1, 0};
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    mindist = -1;
                    auto dist = grid;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    while (q.size()) {
                        auto ij = q.front();
                        q.pop();
                        for (int d=0; d<4; ++d) {
                            int i = ij.first + delta[d];
                            int j = ij.second + delta[d+1];
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                                grid[i][j]--;
                                dist[i][j] = dist[ij.first][ij.second] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.emplace(i, j);
                                if (mindist < 0 || mindist > total[i][j])
                                    mindist = total[i][j];
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return mindist;
    }
};



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
