//
//  482_License_Key_Formatting.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/21/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    // T = O(n).
    // Note: for a string S,  S += char is faster than S = char + S.
    // If we need to insert at the front, we the better append first and then reverse it
public:
    string licenseKeyFormatting(string S, int K) {
        int cnt = 0;
        string result = "";
        for(auto it = S.rbegin(); it != S.rend(); it++){
            if(*it != '-'){
                //Return type of toupper() is INT, should be converted into char
                result += char(toupper(*it));
                cnt = (++cnt) % K;
                if(cnt == 0){
                    result += '-';
                }
            }
        }
        reverse(result.begin(), result.end());
        return (!result.empty() && result[0] == '-')? result.substr(1) : result;
    }
};
