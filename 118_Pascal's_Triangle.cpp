//
//  118_Pascal's_Triangle.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rtn;
        for(int i = 0; i < numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i; j++){
                row.push_back(rtn[i - 1][j - 1] + rtn[i - 1][j]);
            }
            if(i > 0){
                row.push_back(1);
            }
            rtn.push_back(row);
        }
        return rtn;
    }
};