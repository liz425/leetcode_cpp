//
//  174_Dungeon_Game.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Of course, we can use a vector DP[n] rather than a 2D matrix
    //Moreover, we can store HP in the dungeon matrix
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty() || dungeon[0].empty())
            return 1;
        int m = (int)dungeon.size();
        int n = (int)dungeon[0].size();
        vector<vector<int>> DP(m, vector<int>(n, 1));
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                int HP = INT_MAX;
                if(i < m - 1)
                    HP = min(HP, DP[i + 1][j]);
                if(j < n - 1)
                    HP = min(HP, DP[i][j + 1]);
                if(HP == INT_MAX)
                    HP = 1;
                DP[i][j] = max(1, HP - dungeon[i][j]);
            }
        }
        return DP[0][0];
    }
};
