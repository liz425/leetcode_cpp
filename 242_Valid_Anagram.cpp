//
//  242_Valid_Anagram.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }else{
            //initialize to 0
            int chr[26] = {};
            
            for(int i = 0; i < s.length(); i++){
                //change from char to int
                chr[(int)s[i] - 97]++;
                chr[(int)t[i] - 97]--;
                //or chr[s[i] % 26]++; chr[t[i] % 26]--;
            }
            
            for(int i = 0; i < 26; i++){
                if(chr[i] != 0){
                    return false;
                }
            }
            return true;
        }
    }
};