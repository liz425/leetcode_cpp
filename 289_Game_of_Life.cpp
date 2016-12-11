//
//  289_Game_of_Life.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/9/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = (int)board.size();
        int n = m ? (int)board[0].size() : 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int cnt = -board[i][j];
                for(int p = max(i - 1, 0); p < min(i + 2, m); p++){
                    for(int q = max(j - 1, 0); q < min(j + 2, n); q++){
                        cnt += board[p][q] & 1;
                    }
                }
                if(cnt == 3 || (board[i][j] == 1 && cnt == 2)){
                    board[i][j] |= 2;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
