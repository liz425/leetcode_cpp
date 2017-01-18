//
//  361_Bomb_Enemy.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/4/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //T = O(n^2)
    //Use 2 2D matrix to record num of enemies can be killed in horizontal and vertical direction for each position
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        if(m == 0){
            return 0;
        }
        int n = (int)grid[0].size();
        int maxCnt = 0;
        vector<vector<int>> horizontal(m, vector<int>(n, 0));
        vector<vector<int>> vertical(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            int cnt = 0;
            int start = 0, j = 0;
            while(j < n){
                if(grid[i][j] == 'E'){
                    cnt++;
                }
                if(grid[i][j] == 'W' || j == n - 1){
                    int end = (grid[i][j] == 'W')? j - 1 : j;
                    for(int index = start; index <= end; index++){
                        if(grid[i][index] == '0'){
                            horizontal[i][index] = cnt;
                        }
                    }
                    cnt = 0;
                    start = j + 1;
                }
                j++;
            }
        }
        
        for(int j = 0; j < n; ++j){
            int cnt = 0;
            int start = 0, i = 0;
            while(i < m){
                if(grid[i][j] == 'E'){
                    cnt++;
                }
                if(grid[i][j] == 'W' || i == m - 1){
                    int end = (grid[i][j] == 'W')? i - 1 : i;
                    for(int index = start; index <= end; index++){
                        if(grid[index][j] == '0'){
                            vertical[index][j] = cnt;
                        }
                    }
                    cnt = 0;
                    start = i + 1;
                }
                i++;
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                //cout << horizontal[i][j] << " " << vertical[i][j] << endl;
                maxCnt = max(maxCnt, horizontal[i][j] + vertical[i][j]);
            }
        }
        return maxCnt;
    }
};
