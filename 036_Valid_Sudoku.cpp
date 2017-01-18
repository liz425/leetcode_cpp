//
//  36_Valid_Sudoku.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //use bit operation, fast and concise
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<short> col(9, 0);
        vector<short> block(9, 0);
        vector<short> row(9, 0);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = 1 << (board[i][j] - '0');
                    if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                        return false;
                    row[i] |= idx;
                    col[j] |= idx;
                    block[i/3 * 3 + j/3] |= idx;
                }
            }
        }
        return true;
    }
};



class Solution {
    //run slowly...
public:
    bool isValidVector(vector<char>& in){
        int flag[9] = {0,0,0,0,0,0,0,0,0};
        for(int i = 0; i < 9; i++){
            if(in[i] == '.'){
                continue;
            }else{
                if(++flag[in[i] - '1'] > 1){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            //check each row
            if(!isValidVector(board[i])){
                return false;
            }
            
            //check each column
            vector<char> tmp1;
            for(int j = 0; j < 9; j++){
                tmp1.push_back(board[j][i]);
            }
            if(!isValidVector(tmp1)){
                return false;
            }
        }
        //check each square
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<char> tmp2;
                for(int m = 0; m < 3; m++){
                    for(int n = 0; n < 3; n++){
                        tmp2.push_back(board[i+m][j+n]);
                    }
                }
                if(!isValidVector(tmp2)){
                    return false;
                }
            }
        }
        return true;
    }
};
