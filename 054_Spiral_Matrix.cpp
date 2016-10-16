//
//  054_Spiral_Matrix.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty())
            return result;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<vector<int>> directs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ipos = 0, jpos = -1;
        int dir = 0;
        //n is the length that current traversal should go through
        while(n > 0){
            for(int i = 0; i < n; ++i){
                ipos += directs[dir][0];
                jpos += directs[dir][1];
                result.push_back(matrix[ipos][jpos]);
            }
            //now change direction, decrease current dimension length
            m--;
            swap(m, n);
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
