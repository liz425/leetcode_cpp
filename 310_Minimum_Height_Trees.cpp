//
//  310_Minimum_Height_Trees.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/9/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
    //T = O(n), Space = O(n).  Since it's tree-like graph, #_edge is n - 1.
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n);
        //construct graph
        for(auto item : edges){
            graph[item.first].insert(item.second);
            graph[item.second].insert(item.first);
        }
        int cnt = n;
        //use fringe to store leaves node
        queue<int> fringe;
        for(int i = 0; i < n; ++i){
            if(graph[i].size() <= 1){   //'<=', in case of just one single root, degree could be 0
                fringe.push(i);
            }
        }
        while(cnt > 2){
            int k = (int)fringe.size();
            cnt -= k;
            while(k-- > 0){
                int v = fringe.front();
                int w = *(graph[v].begin());
                fringe.pop();
                graph[w].erase(v);
                if(graph[w].size() == 1){
                    fringe.push(w);
                }
            }
        }
        vector<int> result;
        while(!fringe.empty()){
            result.push_back(fringe.front());
            fringe.pop();
        }
        return result;
    }
};
