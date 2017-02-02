//
//  394_Decode_String.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/22/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        string result = decodeHelper(s, index);
        return result;
    }
    string decodeHelper(string& s, int& index){
        string result = "";
        string times = "";
        while(index < s.size()){
            if(isdigit(s[index])){
                times += s[index];
            }else if(s[index] == '['){
                index++;
                string rtn = decodeHelper(s, index);
                int n = stoi(times);
                while(n-- > 0){
                    result += rtn;
                }
                times = "";
            }else if(s[index] == ']'){
                break;
            }else{
                result += s[index];
            }
            index++;
        }
        return result;
    }
};


/*
int main(void){
    Solution ss;
    cout << ss.decodeString("") << endl;
}
*/
