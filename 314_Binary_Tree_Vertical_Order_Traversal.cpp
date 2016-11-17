//
//  314_Binary_Tree_Vertical_Order_Traversal.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
    //T = O(n), n = number of nodes.   Space = O(n)
    //BFS, push both node and its position into the queue;
    //Use map, which is sorted, rather than unordered_map
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        map<int, vector<int>> vertical;
        queue<pair<TreeNode*, int>> fringe;
        fringe.push(make_pair(root, 0));
        //BFS
        while(!fringe.empty()){
            auto current = fringe.front();
            fringe.pop();
            vertical[current.second].push_back(current.first->val);
            if(current.first->left)
                fringe.push(make_pair(current.first->left, current.second - 1));
            if(current.first->right)
                fringe.push(make_pair(current.first->right, current.second + 1));
        }
        for(auto col : vertical){
            result.push_back(col.second);
        }
        return result;
    }
};


