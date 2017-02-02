//
//  345_Reverse_Vowels_of_a_String.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Only one while loop.
public:
    string reverseVowels(string s) {
        if(s.empty()){
            return s;
        }
        int i = 0, j = (int)s.size() - 1;
        while(i < j){
            if(!isVowel(s[i])){
                ++i;
            }else if(!isVowel(s[j])){
                --j;
            }else{
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
    bool isVowel(char c){
        c = char(tolower(c));
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};



class Solution {
public:
    inline bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = (int)s.length() - 1;
        while(i <= j){
            while(!isVowel(s[i]) && i < j){
                i++;
            }
            while(!isVowel(s[j]) && i < j){
                j--;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
