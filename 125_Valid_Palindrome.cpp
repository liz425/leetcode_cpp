//
//  125_Valid_Palindrome.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;


class Solution {
public:
    bool isAlphanumeric(char c){
        return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57));
    }
    bool isEqual(char a, char b){
        if(a >= 65 && a <= 90){
            a += 32;
        }
        if(b >= 65 && b <= 90){
            b += 32;
        }
        return (a == b);
    }
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size();
        while(i <= j){
            while(!isAlphanumeric(s[i]) && i < j){
                i++;
            }
            while(!isAlphanumeric(s[j]) && i < j){
                j--;
            }
            if(!isEqual(s[i], s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};