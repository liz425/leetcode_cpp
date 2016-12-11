//
//  451_Sort_Characters_By_Frequency.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution3 {
    //bucket sort. Theoritically O(n), but slower than Solution1/2
public:
    string frequencySort(string s) {
        int maxFre = 0;
        unordered_map<char, int> hm;
        for(char ch : s){
            hm[ch]++;
            maxFre = max(maxFre, hm[ch]);
        }
        //bucket sort
        vector<string> buckets(maxFre + 1, "");
        for(auto item : hm){
            buckets[item.second] += item.first;
        }
        string result = "";
        for(int i = maxFre; i >= 1; --i){
            for(char ch : buckets[i]){
                result += string(i, ch);
            }
        }
        return result;
    }
};

class Solution2 {
    //count first, then sort, T = O(k*logk), k is number of distinguished chars. k could be as large as n
    static bool comp(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {
        unordered_map<char, int> hm;
        for(char ch : s){
            hm[ch]++;
        }
        vector<pair<char,int>> data;
        for(auto item : hm){
            data.push_back(item);
        }
        sort(data.begin(), data.end(), comp);
        string result = "";
        for(auto item : data){
            result += string(item.second, item.first);
        }
        return result;
    }
};






class comp{
public:
    bool operator()(pair<char, int> a, pair<char, int> b){
        return a.second < b.second;
    }
};
class Solution {
    //count first, then use priority_queue to sort
    //T = O(k*logk), k is number of distinguished chars. k could be as large as n
public:
    string frequencySort(string s) {
        unordered_map<char, int> hm;
        for(char ch : s){
            hm[ch]++;
        }
        priority_queue<pair<char,int>, vector<pair<char, int>>, comp> pq;
        for(auto item : hm){
            pq.push(item);
        }
        string result = "";
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            result += string(item.second, item.first);
        }
        return result;
    }
};
