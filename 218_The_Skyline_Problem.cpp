//
//  218_The_Skyline_Problem.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/4/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //note that the input is already sorted based on the left x position
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        //int building pair, first = bulding height, second = building end point
        priority_queue<pair<int, int>> livBuilds;
        int buildIndex = 0, lens = (int)buildings.size();
        int curX = 0, curH = 0;
        while(buildIndex < lens || !livBuilds.empty()){
            if(livBuilds.empty() || (buildIndex < lens && livBuilds.top().second >= buildings[buildIndex][0])){
                curX = buildings[buildIndex][0];
                while(buildIndex < lens && buildings[buildIndex][0] == curX){
                    livBuilds.push(make_pair(buildings[buildIndex][2], buildings[buildIndex][1]));
                    buildIndex++;
                }
            }else{
                curX = livBuilds.top().second;
                while(!livBuilds.empty() && livBuilds.top().second <= curX){
                    livBuilds.pop();
                }
            }
            curH = livBuilds.empty()? 0 : livBuilds.top().first;
            if(result.empty() || curH != result.back().second){
                result.push_back(make_pair(curX, curH));
            }
        }
        return result;
    }
};


/*
int main(){
    Solution ss;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<pair<int, int>> result = ss.getSkyline(buildings);
    
}
*/
