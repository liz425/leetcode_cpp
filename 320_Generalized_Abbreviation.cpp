//
//  320_Generalized_Abbreviation.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/23/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        vector<int> candid;
        helper(result, candid, word, (int)word.size(), 0);
        return result;
    }
    void helper(vector<string>& result, vector<int>& candid, string& word, int len, int index){
        if(index >= len){
            result.push_back(genAbbre(word, candid));
        }else{
            candid.push_back(0);
            helper(result, candid, word, len, index + 1);
            candid.back() = 1;
            helper(result, candid, word, len, index + 1);
            candid.pop_back();
        }
    }
    string genAbbre(string& word, vector<int>& candid){
        int cnt = 0;
        string result = "";
        for(int i = 0; i < candid.size(); ++i){
            if(candid[i] == 0){
                result += word[i];
            }else if(i == candid.size() - 1 || candid[i + 1] == 0){
                result += to_string(cnt + 1);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        return result;
    }
};
