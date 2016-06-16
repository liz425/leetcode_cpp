//
//  151_Reverse_Words_in_a_String.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        vector<string> ss;
        string word;
        s += ' ';
        for(char& chr : s){
            if(chr != ' '){
                word += chr;
            }else{
                if(word.size() != 0){
                    ss.push_back(word);
                    word = "";
                }
            }
        }
        
        string result;
        for(int i = (int)ss.size() - 1; i >= 0; --i){
            result += (" " + ss[i]);
        }
        if(result.size() == 0){
            s = "";
        }else{
            s = result.substr(1, (int)result.size() - 1);
        }
    }
};

/*
int main(){
    string in = "";
    Solution ss;
    ss.reverseWords(in);
    cout << in << endl;
    return 0;
}
*/