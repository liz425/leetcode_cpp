//
//  102_Binar_Tree_Level_Order_Traversal.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
    //BFS
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rtn;
        vector<int> level;
        if(root == NULL){
            return rtn;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        TreeNode* tail = root;
        while(!bfs.empty()){
            TreeNode* head = bfs.front();
            bfs.pop();
            level.push_back(head->val);
            if(head->left != NULL){
                bfs.push(head->left);
            }
            if(head->right != NULL){
                bfs.push(head->right);
            }
            if(head == tail){
                rtn.push_back(level);
                level.clear();
                if(!bfs.empty()){
                    tail = bfs.back();
                }
            }
        }
        
        return rtn;
    }
};