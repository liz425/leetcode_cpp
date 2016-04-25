//
//  014_Longest_Common_Prefix.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int i = 0;
        if(strs.empty()){
            return longest;
        }
        while(strs[0][i] != '\0'){
            for(int j = 1; j < (int)strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return longest;
                }
            }
            longest += strs[0][i++];
        }
        return longest;
    }
};