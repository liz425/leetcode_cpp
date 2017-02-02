//
//  271_Encode_and_Decode_Strings.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/22/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs){
            int len = (int)str.size();
            result += '[' + to_string(len) + ']' + str;
        }
        return result;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        string len = "";
        while(i < s.size()){
            if(s[i] == '['){
                len = "";
            }else if(s[i] == ']'){
                int n = stoi(len);
                result.push_back(s.substr(i + 1, n));
                i += n;
            }else{
                len += s[i];
            }
            ++i;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
