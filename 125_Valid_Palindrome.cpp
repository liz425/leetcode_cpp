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
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
    bool isEqual(char a, char b){
        if(a >= 'A' && a <= 'Z'){
            a += 'a' - 'A';
        }
        if(b >= 'A' && b <= 'Z'){
            b += 'a' - 'A';
        }
        return (a == b);
    }
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while(i <= j){
            while(!isAlphanumeric(s[i]) && i < j){
                i++;
            }
            while(!isAlphanumeric(s[j]) && i < j){
                j--;
            }
            //either that both s[i], s[j] are legal ones, or i == j
            if(!isEqual(s[i], s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
