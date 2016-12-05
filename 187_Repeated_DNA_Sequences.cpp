//
//  187_Repeated_DNA_Sequences.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if((int)s.size() < 10){
            return result;
        }
        unordered_map<string, int> hp;
        string str = "a" + s.substr(0, 9);
        for(int i = 9; i < (int)s.size(); ++i){
            str = str.substr(1) + s[i];
            hp[str]++;
            if(hp[str] == 2){
                result.push_back(str);
            }
        }
        return result;
    }
};
