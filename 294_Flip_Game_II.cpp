//
//  294_Flip_Game_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Based on Solution, just use hm to memorise
    unordered_map<string, bool> hm;
public:
    bool canWin(string s) {
        //add helper just because helper can take s as reference, save space
        return helper(s);
    }
    bool helper(string& s) {
        int n = (int)s.size();
        if(hm.find(s) != hm.end()){
            return hm[s];
        }
        bool result = false;
        for(int i = 0; i < n - 1 && !result; ++i){
            if(s[i] == '+' && s[i + 1] == '+'){
                s[i] = '-';
                s[i + 1] = '-';
                if(!helper(s)){
                    result = true;
                }
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        hm[s] = result;
        return result;
    }
};



class Solution {
public:
    bool canWin(string s) {
        //add helper just because helper can take s as reference, save space
        return helper(s);
    }
    bool helper(string& s) {
        int n = (int)s.size();
        bool result = false;
        for(int i = 0; i < n - 1 && !result; ++i){
            if(s[i] == '+' && s[i + 1] == '+'){
                s[i] = '-';
                s[i + 1] = '-';
                if(!helper(s)){
                    result = true;
                }
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return result;
    }
};
