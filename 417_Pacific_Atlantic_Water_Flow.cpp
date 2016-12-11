//
//  417_Pacific_Atlantic_Water_Flow.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //BFS, T = O(m * n)
    //Based on solution1, instead of initialized 4 borders, we just initial left up corner and bottom right corner.
    //Also we add node to result within the BFS process, do not need the final loop to add nodes to result
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if(matrix.empty() || matrix[0].empty()){
            return result;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<vector<int>> record(m, vector<int>(n, 0));
        vector<int> borderX = {0, m - 1};
        vector<int> borderY = {0, n - 1};
        //BFS twice
        vector<int> visits = {0, 1};
        vector<int> deltas = {1, 0, -1, 0, 1};
        for(int k = 0; k < 2; ++k){
            queue<pair<int, int>> fringe;
            fringe.push(make_pair(borderX[k], borderY[k]));
            record[borderX[k]][borderY[k]] |= 1 << visits[k];
            while(!fringe.empty()){
                auto node = fringe.front();
                if((record[node.first][node.second] & 0x3) == 0x3){
                    result.push_back(make_pair(node.first, node.second));
                }
                fringe.pop();
                for(int i = 0; i < 4; ++i){
                    int x = node.first + deltas[i];
                    int y = node.second + deltas[i + 1];
                    if(x >= 0 && x < m && y >= 0 && y < n && !(record[x][y] & (1 << visits[k]))){
                        if(x == borderX[k] || y == borderY[k] || matrix[x][y] >= matrix[node.first][node.second]){
                            fringe.push(make_pair(x, y));
                            record[x][y] |= 1 << visits[k];
                        }
                    }
                }
            }
        }
        return result;
    }
};




class Solution {
    //BFS, T = O(m * n)
    //Moreover, instead of initialize boundry, we can simply write water function.
    //Then, if an node is near the water, or val is >= previous node, it's true;
    //Optimized in Solution2
    //We can also use DFS.
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if(matrix.empty() || matrix[0].empty()){
            return result;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<vector<int>> record(m, vector<int>(n, 0));
        //BFS twice
        vector<int> starts = {1, 0};
        vector<int> ends = {m, m - 1};
        vector<int> xs = {0, m - 1};
        vector<int> ys = {0, n - 1};
        vector<int> visits = {0, 1};
        vector<int> deltas = {1, 0, -1, 0, 1};
        for(int k = 0; k < 2; ++k){
            queue<pair<int, int>> fringe;
            for(int i = 0; i < n; ++i){
                fringe.push(make_pair(xs[k], i));
                record[xs[k]][i] |= 1 << visits[k];
            }
            for(int i = starts[k]; i < ends[k]; ++i){
                fringe.push(make_pair(i, ys[k]));
                record[i][ys[k]] |= 1 << visits[k];
            }
            while(!fringe.empty()){
                auto node = fringe.front();
                fringe.pop();
                for(int i = 0; i < 4; ++i){
                    int x = node.first + deltas[i];
                    int y = node.second + deltas[i + 1];
                    if(x >= 0 && x < m && y >= 0 && y < n && !(record[x][y] & (1 << visits[k]))){
                        if(matrix[x][y] >= matrix[node.first][node.second]){
                            fringe.push(make_pair(x, y));
                            record[x][y] |= 1 << visits[k];
                        }
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((record[i][j] & 0x3) == 0x3){
                    result.push_back(make_pair(i, j));
                }
            }
        }
        return result;
    }
};
