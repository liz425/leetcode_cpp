//
//  316_Remove_Duplicate_Letters.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> candids;
        vector<int> cnt(26, 0);
        for(auto ch : s){
            cnt[ch - 'a']++;
        }
        vector<bool> visited(26, 0);
        for(auto ch : s){
            cnt[ch - 'a']--;
            if(!visited[ch - 'a']){
                while(!candids.empty() && candids.top() > ch && cnt[candids.top() - 'a'] > 0){
                    visited[candids.top() - 'a'] = false;
                    candids.pop();
                }
                candids.push(ch);
                visited[ch - 'a'] = true;
            }
        }
        string result;
        while(!candids.empty()){
            result.push_back(candids.top());
            candids.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
