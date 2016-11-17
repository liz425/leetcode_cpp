//
//  133_Clone_Graph.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL){
            return NULL;
        }
        if(hash.find(node) == hash.end()){
            hash[node] = new UndirectedGraphNode(node->label);
        }
        for(auto neighbor : node->neighbors){
            if(hash.find(neighbor) == hash.end()){
                //unvisited node, DFS
                cloneGraph(neighbor);
            }
            hash[node]->neighbors.push_back(hash[neighbor]);
        }
        return hash[node];
    }
};
