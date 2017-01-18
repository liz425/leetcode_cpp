//
//  037_Sudoku_Solver.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/17/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
private:
    vector<int> rows;
    vector<int> cols;
    vector<int> blocks;
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.assign(9, 0x1ff);
        cols.assign(9, 0x1ff);
        blocks.assign(9, 0x1ff);
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int val = 1 << (board[i][j] - '1');
                    rows[i] &= ~val;
                    cols[j] &= ~val;
                    blocks[i / 3 * 3 + j / 3] &= ~val;
                }
            }
        }
        solver(board, 0);
        return;
    }
    bool solver(vector<vector<char>>& board, int index){
        int i = index / 9;
        int j = index % 9;
        while(index < 81 && board[i][j] != '.'){
            index++;
            i = index /9;
            j = index % 9;
        }
        if(index >= 81){
            return true;
        }
        int mask = rows[i] & cols[j] & blocks[i / 3 * 3 + j / 3];
        while(mask != 0){
            int candid = mask & (-mask);
            int cnt = 0;
            while(candid != 0){
                candid = candid >> 1;
                cnt++;
            }
            mask -= mask & (-mask);
            board[i][j] = char('0' + cnt);
            rows[i] &= ~(1 << (cnt - 1));
            cols[j] &= ~(1 << (cnt - 1));
            blocks[i / 3 * 3 + j / 3] &= ~(1 << (cnt - 1));
            if(solver(board, index + 1)){
                return true;
            }
            board[i][j] = '.';
            rows[i] |= (1 << (cnt - 1));
            cols[j] |= (1 << (cnt - 1));
            blocks[i / 3 * 3 + j / 3] |= (1 << (cnt - 1));
        }
        return false;
    }
};
