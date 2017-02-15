//
//  249_Group_Shifted_Strings.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/6/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hm;
        for(auto& s : strings){
            string rtn = convert(s);
            hm[rtn].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& item : hm){
            result.push_back(item.second);
        }
        return result;
    }
    string convert(string s){
        if(s.empty()){
            return "";
        }
        char start = s[0];
        string result = "";
        for(char ch : s){
            result += char((ch - start + 26) % 26 + 'a');
        }
        return result;
    }
};
