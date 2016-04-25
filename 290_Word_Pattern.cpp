//
//  290_Word_Pattern.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;


class Solution2 {
    //istringstream, easily split string into words
public:
    bool wordPattern(string pattern, string str) {
        int cnt = 0;
        int len = (int)pattern.size();
        unordered_map<char, int> map_p;
        unordered_map<string, int> map_s;
        istringstream in(str);
        for(string word; in >> word; cnt++){
            if(cnt >= len || map_p[pattern[cnt]] != map_s[word]){
                return false;
            }else{
                map_p[pattern[cnt]] = map_s[word] = cnt + 1;
            }
        }
        return (len == cnt);
    }
};


class Solution {
    //get word through extracting str character by character
public:
    bool wordPattern(string pattern, string str) {
        int i = 0;
        string word = "";
        char prev = ' ';
        int cnt = 0;
        unordered_map<char, int> map_p;
        unordered_map<string, int> map_s;
        //make sure str always ends with a whitespace
        str += ' ';
        while(str[i] != '\0'){
            if(str[i] != ' '){
                word += str[i];
            }else{
                if(prev != ' '){
                    cnt++;
                    if(cnt > pattern.length()){
                        return false;
                    }else{
                        if(map_p[pattern[cnt - 1]] == map_s[word]){
                            map_p[pattern[cnt - 1]] = cnt;
                            map_s[word] = cnt;
                        }else{
                            return false;
                        }
                    }
                }
                word = "";
            }
            prev = str[i];
            i++;
        }
        
        return (pattern.length() == cnt);
    }
};