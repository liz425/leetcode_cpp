//
//  038_Count_and_Say.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    string countAndSay(int n) {
        //mark the end of string as #
        string result = to_string(1);
        for(int k = 1; k < n; k++){
            string num = result + '#';
            result = "";
            int start = 0;
            for(int i = 0; i < (int)num.size(); ++i){
                if(i != 0 && num[i] != num[i - 1]){
                    result += to_string(i - start) + num[i - 1];
                    start = i;
                }
            }
        }
        return result;
    }
};



class Solution {
public:
    string helper(string str){
        string rtn("");
        char prev = str[0];
        int cnt = 0;
        //str[str.length()] will return '\0'
        //We'd better not use '\0', but rather append an extra non digit character
        for(int i = 0; i <= (int)str.length(); prev = str[i++]){
            if(str[i] != prev){
                rtn += to_string(cnt) + prev;
                cnt = 0;
            }
            cnt++;
        }
        return rtn;
    }
    string countAndSay(int n) {
        string str = "1";
        for(int i = 1; i < n; i++){
            str = helper(str);
        }
        return str;
    }
};
