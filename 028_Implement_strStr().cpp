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
        for(int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; i++){
            bool found = true;
            for(int j = 0; j < (int)needle.length(); j++){
                if(haystack[i + j] != needle[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                return i;
            }
        }
        return -1;
    }
};


