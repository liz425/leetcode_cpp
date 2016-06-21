//
//  221_Maximal_Square.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    //DP, state equation: edge[i][j] = min(left[j], up[j], edge[i - 1][j - 1] + 1);
    //PS: Another solution, state equation edge[i][j] = min(edge[i][j], edge[i - 1][j], edge[i][j - 1]) 
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