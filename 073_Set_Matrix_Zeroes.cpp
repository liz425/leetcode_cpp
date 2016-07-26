//
//  073_Set_Matrix_Zeroes.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/25/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = static_cast<int>(matrix.size());
        if(height == 0) return;
        int width = static_cast<int>(matrix[0].size());
        bool firstRow = false;
        for(int i = 0; i < width; ++i){
            if(matrix[0][i] == 0){
                firstRow = true;
                break;
            }
        }
        for(int i = 0; i < width; ++i){
            for(int j = 0; j < height; ++j){
                if(matrix[j][i] == 0){
                    matrix[0][i] = 0;
                    break;
                }
            }
        }
        for(int i = 1; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if(matrix[i][j] == 0){
                    matrix[i].assign(width, 0);
                    break;
                }
            }
        }
        for(int i = 0; i < width; ++i){
            if(matrix[0][i] == 0){
                for(int j = 1; j < height; ++j){
                    matrix[j][i] = 0;
                }
            }
        }
        if(firstRow){
            matrix[0].assign(width, 0);
        }
    }
};

/*
int main(){
    Solution ss;
    vector<vector<int>> input = {{0,1,0,0,1,0},{1,1,2,6,3,0},{0,2,1,6,3,0},{9,9,9,9,3,1}};
    vector<vector<int>> matrix = {{1,0,1,0}};
    ss.setZeroes(matrix);
}
*/