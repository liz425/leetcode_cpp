//
//  286_Walls_and_Gates.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty())
            return;
        int m = (int)rooms.size();
        int n = (int)rooms[0].size();
        queue<pair<int, int>> fringe;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rooms[i][j] == 0){
                    fringe.push(make_pair(i, j));
                }
            }
        }
        vector<int> delta = {0, 1, 0, -1, 0};
        while(!fringe.empty()){
            auto pos = fringe.front();
            fringe.pop();
            for(int k = 0; k < 4; ++k){
                int i = pos.first + delta[k];
                int j = pos.second + delta[k + 1];
                if(i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] == 2147483647){
                    rooms[i][j] = rooms[pos.first][pos.second] + 1;
                    fringe.push(make_pair(i, j));
                }
            }
        }
        return;
    }
};
