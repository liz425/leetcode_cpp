//
//  102_Binary_Tree_Level_Order_Traversal.cpp
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


class Solution2 {
    //DFS
public:
    void DFSHelper(TreeNode* root, vector<vector<int>>& rtn, int level){
        if(root == NULL){
            return;
        }
        if(rtn.size() <= level){
            vector<int> n {};
            rtn.push_back(n);
        }
        rtn[level].push_back(root->val);
        DFSHelper(root->left, rtn, level + 1);
        DFSHelper(root->right, rtn, level + 1);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rtn;
        DFSHelper(root, rtn, 0);
        return rtn;
    }
};


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