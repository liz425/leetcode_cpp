//
//  059_Spiral_Matrix_II.cpp
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mt(n, vector<int>(n));
        int i = 0, j = 0, k = 1;
        while(k <= n * n){
            for(int p = j; p < n - j; p++){
                mt[i][p] = k++;
            }
            for(int p = i + 1; p < n - i; p++){
                mt[p][n - j - 1] = k++;
            }
            for(int p = n - j - 2; p >= j; p--){
                mt[n - i - 1][p] = k++;
            }
            for(int p = n - i - 2; p > i; p--){
                mt[p][j] = k++;
            }
            i++;
            j++;
        }
        return mt;
    }
};