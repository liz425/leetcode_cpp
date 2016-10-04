//
//  261_Graph_Valid_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
    //union-find
public:
    vector<int> father;
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for(int i = 0; i < n; ++i){
            father.push_back(i);
        }
        int cnt = n;    //# of parts
        for(auto edge : edges){
            if(un(edge.first, edge.second))
                cnt--;          //successful union
            else
                return false;   //circle
        }
        return (cnt == 1);
    }
    int find(int p){
        int son = p;
        while(father[son] != son){
            son = father[son];
        }
        int ancestor = son;
        son = p;
        while(father[son] != son){
            int parent = father[son];
            father[son] = ancestor;
            son = parent;
        }
        return ancestor;
    }
    //return true if union success, return false if there are already in the same set
    bool un(int p, int q){
        int father_p = find(p);
        int father_q = find(q);
        if(father_p != father_q){
            father[father_p] = father_q;
            return true;
        }else{
            return false;
        }
    }
};
