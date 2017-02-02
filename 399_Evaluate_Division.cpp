//
//  399_Evaluate_Division.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/23/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    unordered_map<string, unordered_map<string, double>> graph;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        //build graph
        buildGraph(equations, values);
        vector<double> result;
        for(auto& query : queries){
            string start = query.first;
            string end = query.second;
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                //If start or end is not in the graph, return -1.0.
                //E.g., ["x", "x"], since "x" is not in graph, we should return -1.0 rather than 1.0
                result.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double ans = DFS(visited, start, end, 1.0);
            if(visited.count(end) == 0){
                ans = -1.0;
            }
            result.push_back(ans);
        }
        return result;
    }
    void buildGraph(vector<pair<string, string>>& equations, vector<double>& values){
        int n = (int)equations.size();
        for(int i = 0; i < n; ++i){
            auto equation = equations[i];
            graph[equation.first][equation.second] = values[i];
            graph[equation.second][equation.first] = 1.0 / values[i];
        }
    }
    double DFS(unordered_set<string>& visited, string current, string target, double value){
        visited.insert(current);
        if(current == target){
            return value;
        }
        for(auto& neighbor : graph[current]){
            if(visited.count(neighbor.first) > 0){  //already visited
                continue;
            }
            double ans = DFS(visited, neighbor.first, target, value * neighbor.second);
            if(visited.count(target) > 0){     //already found target
                return ans;
            }
        }
        return value;
    }
};
