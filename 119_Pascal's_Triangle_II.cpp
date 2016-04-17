//
//  119_Pascal's_Triangle_II.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rtn;
        rtn.push_back(1);
        long product = 1;
        for(int i = 0; i < rowIndex; i++){
            product *= rowIndex - i;
            product /= i + 1;
            rtn.push_back((int)product);
        }
        return rtn;
    }
};