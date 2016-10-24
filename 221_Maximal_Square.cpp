//
//  221_Maximal_Square.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
public:
    //Use rolling array to optimize space complexity to O(n) rather than O(m*n)
    //DP: state equation
    //If current node == '1': square[i][j] = min(square[i][j], square[i - 1][j], square[i][j - 1]) + 1
    //Else: square[i][j] = 0
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int square[2][n];
        int maxArea = 0;
        for(int i = 0; i < n; ++i){
            square[0][i] = matrix[0][i] - '0';
            maxArea = max(maxArea, square[0][i]);
        }
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j == 0){
                    square[i % 2][0] = matrix[i][j] - '0';
                }else{
                    square[i % 2][j] = (matrix[i][j] == '1')? min(min(square[(i - 1) % 2][j - 1], square[i % 2][j - 1]), square[(i - 1) % 2][j]) + 1: 0;
                }
                maxArea = max(maxArea, (int)pow(square[i % 2][j], 2));
            }
        }
        return maxArea;
    }
};


class Solution2 {
public:
    //Update, this could be better using 1 dimension DP, rather than 2 dimension, save space. See solution3
    //DP: state equation
    //If current node == '1': square[i][j] = min(square[i][j], square[i - 1][j], square[i][j - 1]) + 1
    //Else: square[i][j] = 0
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<vector<int>> square(m, vector<int>(n, 0));
        int maxArea = 0;
        for(int i = 0; i < m; ++i){
            square[i][0] = matrix[i][0] - '0';
            maxArea = max(maxArea, square[i][0]);
        }
        for(int i = 0; i < n; ++i){
            square[0][i] = matrix[0][i] - '0';
            maxArea = max(maxArea, square[0][i]);
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                square[i][j] = (matrix[i][j] == '1')? min(min(square[i - 1][j - 1], square[i][j - 1]), square[i - 1][j]) + 1: 0;
                maxArea = max(maxArea, (int)pow(square[i][j], 2));
            }
        }
        return maxArea;
    }
};


class Solution {
public:
    //DP, state equation: edge[i][j] = min(left[j], up[j], edge[i - 1][j - 1] + 1);
    //PS: Another solution, state equation edge[i][j] = min(edge[i][j], edge[i - 1][j], edge[i][j - 1]) + 1. See solution 2;
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int height = (int)matrix.size();
        int width = (int)matrix[0].size();
        //edge[i][j]: length of square with bottom_right located in matrix[i][j]
        vector<vector<int>> edge(height, vector<int>(width));
        vector<int> up(width, 0);
        vector<int> left(width, 0);
        int max_edge = 0;
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if(matrix[i][j] == '0'){
                    edge[i][j] = 0;
                    left[j] = 0;
                    up[j] = 0;
                }else{
                    left[j] = (j > 0)? left[j - 1] + 1 : 1;
                    up[j] = (i > 0)? up[j] + 1 : 1;
                    if(i > 0 && j > 0){
                        edge[i][j] = min(min(left[j], up[j]), edge[i - 1][j - 1] + 1);
                    }else{
                        edge[i][j] = 1;
                    }
                }
                max_edge = max(max_edge, edge[i][j]);
            }
        }
        return max_edge * max_edge;
    }
};
