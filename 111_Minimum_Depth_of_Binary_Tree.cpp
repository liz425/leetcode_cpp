//
//  111_Minimum_Depth_of_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        int depth = 1;
        TreeNode* tail = root;
        while(root->left != NULL || root->right != NULL){
            if(root->left != NULL){
                bfs.push(root->left);
            }
            if(root->right != NULL){
                bfs.push(root->right);
            }
            if(root == tail){
                depth++;
                tail = bfs.back();
            }
            root = bfs.front();
            bfs.pop();
        }
        return depth;
    }
};