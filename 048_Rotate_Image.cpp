//
//  048_Rotate_Image.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int swap;
        int n = (int)matrix.size();
        for(int j = 0; j < n / 2; j++){
            for(int i = j; i < n - j - 1; i++){
                swap = matrix[j][i];
                matrix[j][i] = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = swap;
            }
        }
    }
};