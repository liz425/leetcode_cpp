//
//  205_Isomorphic_Strings.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution2 {
    //use array, much faster
public:
    bool isIsomorphic(string s, string t) {
        int maps[256] = {0};
        int mapt[256] = {0};
        int unique = 1;
        for(int i = 0; i < s.length(); i++){
            if(maps[(int)s[i]] != mapt[(int)t[i]]){
                return false;
            }else if(maps[(int)s[i]] == 0){
                maps[(int)s[i]] = unique;
                mapt[(int)t[i]] = unique++;
            }
        }
        return true;
    }
};


class Solution {
    //unordered_map is slow, comparing to array or vector
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        int unique = 1;
        for(int i = 0; i < s.length(); i++){
            if(maps[s[i]] != mapt[t[i]]){
                return false;
            }else if(maps[s[i]] == 0){
                maps[s[i]] = unique;
                mapt[t[i]] = unique++;
            }
        }
        return true;
    }
};