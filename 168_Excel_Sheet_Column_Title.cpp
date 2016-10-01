//
//  168_Excel_Sheet_Column_Title.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n > 0){
            int lastDigit = (n - 1) % 26;
            result = (char)(lastDigit + 'A') + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};