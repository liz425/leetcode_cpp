//
//  103.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        deque<TreeNode*> level;
        level.push_back(root);
        bool forward = true;
        while(!level.empty()){
            int lens = (int)level.size();
            vector<int> tmp;
            TreeNode* cur;
            if(forward){
                while(lens-- > 0){
                    cur = level.front();
                    level.pop_front();
                    tmp.push_back(cur->val);
                    if(cur->left)
                        level.push_back(cur->left);
                    if(cur->right)
                        level.push_back(cur->right);
                }
            }else{
                while(lens-- > 0){
                    cur = level.back();
                    level.pop_back();
                    tmp.push_back(cur->val);
                    if(cur->right)
                        level.push_front(cur->right);
                    if(cur->left)
                        level.push_front(cur->left);
                }
            }
            forward = !forward;
            result.push_back(tmp);
        }
        return result;
    }
};
