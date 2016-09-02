//
//  301_Remove_Invalid_Parentheses.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    unordered_set<string> removeRightParen(string s){
        unordered_set<string> result;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ')' && (i == 0 || s[i - 1] != ')'))
                result.insert(s.substr(0, i) + s.substr(i + 1));
        }
        return result;
    }
    unordered_set<string> removeLeftParen(string s){
        unordered_set<string> result;
        for(int i = (int)s.size() - 1; i >= 0; --i){
            if(s[i] == '(' && (i == s.size() - 1 || s[i + 1] != '('))
                result.insert(s.substr(0, i) + s.substr(i + 1));
        }
        return result;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> candids;
        candids.push_back("");
        int leftParen = 0;
        int rightParen = 0;
        for(int i = 0; i < s.size(); ++i){
            for(auto& item: candids)
                item += s[i];
            if(s[i] == '(')
                leftParen++;
            if(s[i] == ')')
                rightParen++;
            if(rightParen > leftParen){
                unordered_set<string> newCandids;
                for(auto& item: candids){
                    unordered_set<string> expanded = removeRightParen(item);
                    newCandids.insert(expanded.begin(), expanded.end());
                }
                rightParen--;
                candids = vector<string>(newCandids.begin(), newCandids.end());
            }
        }
        
        
        if(leftParen == rightParen)
            return candids;
        
        leftParen = 0;
        rightParen = 0;
        unordered_set<string> finalCandids;
        for(auto& str: candids){
            vector<string> partCandids;
            partCandids.push_back("");
            for(int i = (int)str.size() - 1; i >= 0; --i){
                for(auto& item: partCandids){
                    item = str[i] + item;
                }
                if(str[i] == '(')
                    leftParen++;
                if(str[i] == ')')
                    rightParen++;
                
                
                if(leftParen > rightParen){
                    unordered_set<string> newPartCandids;
                    for(auto& item: partCandids){
                        unordered_set<string> expanded = removeLeftParen(item);
                        newPartCandids.insert(expanded.begin(), expanded.end());
                    }
                    leftParen--;
                    partCandids = vector<string>(newPartCandids.begin(), newPartCandids.end());
                }
            }
            finalCandids.insert(partCandids.begin(), partCandids.end());
        }
        
        vector<string> result(finalCandids.begin(), finalCandids.end());
        return result;
    }
};

/*
int main(){
    Solution ss;
    vector<string> result = ss.removeInvalidParentheses("");
    for(auto& item : result)
        cout << item << endl;
    return 0;
}
 */
