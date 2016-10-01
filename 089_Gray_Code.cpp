//
//  089_Gray_Code.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        gray.push_back(0);
        for(int i = 0; i < n; i++){
            for(int j = pow(2,i) - 1; j >= 0; j--){
                gray.push_back(gray[j] | (0x1 << i));
            }
        }
        return gray;
    }
};