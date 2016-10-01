//
//  017_Letter_Combinations_of_a_Phone_Number.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        ///Remember to check length of digits
        if(digits.length() == 0)
            return result;
        for(char& ch: digits){
            if(ch == '0' || ch == '1')
                return result;
        }
        
        vector<vector<char>> charMap = {{'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}};
        result.push_back("");
        for(char& digit : digits){
            int len = (int)result.size();
            bool firstTrav = true;
            for(char& ch: charMap[digit - '2']){
                if(firstTrav){
                    for(int i = 0; i < len; ++i){
                        result[i] += ch;
                    }
                    firstTrav = false;
                }else{
                    for(int i = 0; i < len; ++i){
                        string newStr = result[i];
                        *newStr.rbegin() = ch;
                        result.push_back(newStr);
                    }
                }
            }
        }
        return result;
    }
};

/*
int main(){
    Solution ss;
    vector<string> result = ss.letterCombinations("235");
    for(auto& str: result)
        cout << str << endl;
}
 */
