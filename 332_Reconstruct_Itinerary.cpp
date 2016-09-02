//
//  332_Reconstruct_Itinerary.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    unordered_map<string, vector<string>> des;
    vector<string> result;
    int length = 0;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto& flight: tickets){
            des[flight.first].push_back(flight.second);
        };
        for(auto& item : des){
            sort(item.second.begin(), item.second.end());
        }
        string curLoc = "JFK";
        result.push_back(curLoc);
        length = (int)tickets.size() + 1;
        DFS(curLoc);
        return result;
    }
    
    bool DFS(string curLoc){
        if(result.size() == length)
            return true;
        int size = (int)des[curLoc].size();
        if(size <= 0)
            return false;
        string next;
        for(int i = 0; i < size; ++i){
            next = des[curLoc][0];
            des[curLoc].erase(des[curLoc].begin());
            result.push_back(next);
            if(DFS(next))
                return true;
            else{
                result.pop_back();
                des[curLoc].push_back(next);
            }
        }
        return false;
    }
};

/*
int main(){
    Solution ss;
    vector<pair<string, string>> in = {make_pair("MUC","LHR"),make_pair("JFK","MUC"),make_pair("SFO","SJC"),make_pair("LHR","SFO")};
    vector<string> result = ss.findItinerary(in);
    for(auto& item : result){
        cout << item << endl;
    }
}
*/