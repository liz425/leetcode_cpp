//
//  058_Length_of_Last_Word.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = (int)s.length() - 1;
        int cnt = 0;
        while(len >= 0){
            if(s[len] == ' ' && cnt > 0){
                break;
            }
            if(s[len] != ' '){
                cnt++;
            }
            len--;
        }
        return cnt;
    }
};