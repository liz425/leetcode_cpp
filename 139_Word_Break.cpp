//
//  139_Word_Break.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    //DP, result[k] store whether s.substr(0, k + 1) can be broken using wordDict
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = (int)s.length();
        if(len == 0)
            return false;
        vector<bool> result(len, false);
        for(int i = 0; i < len; ++i){
            if(wordDict.find(s.substr(0, i + 1)) != wordDict.end()){
                result[i] = true;
            }else{
                for(int j = i; j > 0; --j){
                    if(result[j - 1]){
                        if(wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()){
                            result[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        return result[len - 1];
    }
};

/*
int main(){
    Solution ss;
    string in = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabab";
    unordered_set<string> in2 = {"a","aa","ba"};
    ss.wordBreak(in, in2);
}
*/
