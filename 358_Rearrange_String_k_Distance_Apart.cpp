//
//  358_Rearrange_String_k_Distance_Apart.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class comp{
public:
    bool operator()(pair<char, pair<int,int>> a, pair<char, pair<int,int>> b){
        return (a.second.second == b.second.second)? a.second.first > b.second.first : a.second.second < b.second.second;
    }
};

class Solution {
    //greedy approach
public:
    string rearrangeString(string str, int k) {
        int len = (int)str.size();
        unordered_map<char, int> cnt;
        //pair<char, pair<int,int>>: char, lastIndex, cnt
        priority_queue<pair<char, pair<int,int>>, vector<pair<char, pair<int,int>>>, comp> candids;
        queue<pair<char, pair<int,int>>> window;
        for(int i = 0; i < len; ++i){
            cnt[str[i]]++;
        }
        for(auto item : cnt){
            candids.push(make_pair(item.first, make_pair(INT_MIN, item.second)));
        }
        string result = "";
        for(int i = 0; i < (int)str.size(); ++i){
            if(!window.empty() && window.front().second.first + k <= i){
                candids.push(window.front());
                window.pop();
            }
            if(candids.empty()){
                return "";
            }else{
                auto sel = candids.top();
                candids.pop();
                result += sel.first;
                if(--sel.second.second > 0){
                    sel.second.first = i;
                    window.push(sel);
                }
            }
        }
        return result;
    }
};
