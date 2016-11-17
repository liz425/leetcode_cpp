//
//  028_Implement_strStr().cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = (int)haystack.length();
        int n = (int)needle.length();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (j = 0; j < n; j++){
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};




