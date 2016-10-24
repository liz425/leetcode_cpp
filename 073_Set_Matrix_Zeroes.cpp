//
//  073_Set_Matrix_Zeroes.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/25/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        bool col0 = false;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 0)
                col0 = true;
            for(int j = 1; j < n; ++j)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for(int i = m - 1; i >= 0; --i){    //Order here is important: must scan bottom-up, right-left.
            for(int j = n - 1; j >= 1; --j)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(col0)                        //Thus this line should be later than the inner for-loop,
                matrix[i][0] = 0;           //guarantee that j from n-1 to 1, then 0
        }
    }
};

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
    Solution2 ss;
    vector<vector<int>> matrix = {{0,1,0,0,1,0},{1,1,2,6,3,0},{0,2,1,6,3,0},{9,9,9,9,3,1}};
    ss.setZeroes(matrix);
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
*/
