//
//  363_Max_Sum_of_Rectangle_No_Larger_Than_K.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DP solution
    //The test cases are desined to way more rows rather than columns,
    //So the DP direction is horizontal, an T = (n * n * m * log(m)), since m >> n
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> rowSum(n, 0);
        set<int> recSum;
        int maxPre = INT_MIN;
        for(int i = 0; i < n; ++i){
            rowSum = vector<int>(m, 0);
            for(int j = i; j < n; ++j){
                recSum.clear();
                recSum.insert(0);
                int preSum = 0;
                for(int h = 0; h < m; ++h){
                    rowSum[h] += matrix[h][j];
                    preSum += rowSum[h];
                    auto maxIt = recSum.lower_bound(preSum - k);
                    if(maxIt != recSum.end()){
                        maxPre = max(preSum - *maxIt, maxPre);
                    }
                    recSum.insert(preSum);
                }
            }
        }
        return maxPre;
    }
};


/*
int main(void){
    vector<vector<int>> matrix = {{2, 2, -1}};
    int k = 3;
    Solution ss;
    cout << ss.maxSumSubmatrix(matrix, k) << endl;
}
 */
