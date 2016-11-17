//
//  210_Course_Schedule_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS, T = O(V + E)
private:
    vector<int> color;
public:
    bool DFS(vector<int>& result, vector<vector<int>>& graph, int k){
        color[k] = 1;
        for(int pre : graph[k]){
            if(color[pre] == 1){    //has cycle
                return false;
            }else if(color[pre] == 0){
                if(!DFS(result, graph, pre))
                    return false;   //has cycle
            }
        }
        color[k] = 2;
        result.push_back(k);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        color = vector<int>(numCourses, 0);     //color: 0-white, 1-grey, 2-black
        vector<vector<int>> graph(numCourses, vector<int>(0));
        for(auto pre : prerequisites){
            graph[pre.first].push_back(pre.second);
        }
        vector<int> result;
        for(int i = 0; i < numCourses; ++i){
            if(color[i] == 0){
                if(!DFS(result, graph, i))
                    return vector<int>{};
            }
        }
        return result;
    }
};
