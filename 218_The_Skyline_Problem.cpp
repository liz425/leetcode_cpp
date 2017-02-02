//
//  218_The_Skyline_Problem.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/4/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //Sweep line. T = O(n*logn)
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        vector<pair<int, int>> borders;
        for(auto& building : buildings){
            borders.emplace_back(building[0], -building[2]);    //left border, height will be set to negtive
            borders.emplace_back(building[1], building[2]);
        }
        //sorting order: higher left border -> lower left border -> lower right border -> higher right border
        //This ensure that, when we are updating livbuilds, all those borders (both left and right) at the same X positions will cause at most one change in Y position. This is the most critical step here.
        sort(borders.begin(), borders.end());
        multiset<int> livBuilds{0};
        pair<int, int> current{0, 0};
        for(auto& border : borders){
            if(border.second < 0){
                livBuilds.insert(-border.second);
            }else{
                livBuilds.erase(livBuilds.lower_bound(border.second));
            }
            if(current.second != *livBuilds.rbegin()){
                current.first = border.first;
                current.second = *livBuilds.rbegin();
                result.push_back(current);
            }
        }
        return result;
    }
};




class Solution2 {
    //Sweep line. T = O(n*logn)
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        vector<vector<int>> borders;
        for(auto& building : buildings){
            vector<int> left_border = {building[0], building[2], 0};
            vector<int> right_border = {building[1], building[2], 1};
            borders.push_back(left_border);
            borders.push_back(right_border);
        }
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool{
            return a[0] == b[0] ? a[2] > b[2] : a[0] < b[0];
        };
        sort(borders.begin(), borders.end(), cmp);
        multiset<int> livBuilds;
        int n = (int)borders.size();
        for(int i = 0; i < n; ++i){
            auto& border = borders[i];
            if(!border[2]){
                livBuilds.insert(border[1]);
            }else{
                livBuilds.erase(livBuilds.lower_bound(border[1]));
            }
            if(i != n - 1 && border[0] == borders[i + 1][0]){
                //make sure that the X position of each border is different
                continue;
            }
            int height = livBuilds.empty() ? 0 : *livBuilds.rbegin();
            if(result.empty() || height != result.back().second){
                //make sure that the Y position of two consecutive point is different
                result.push_back(make_pair(border[0], height));
            }
        }
        return result;
    }
};



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
