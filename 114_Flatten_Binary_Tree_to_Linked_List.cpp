//
//  114_Flatten_Binary_Tree_to_Linked_List.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        pre = root;
        flatten(root->left);
        pre->right = root->right;
        flatten(root->right);
        root->right = root->left ? root->left : root->right;
        root->left = NULL;
    }
private:
    TreeNode* pre = NULL;
};


class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        if(root->left){
            flatten(root->left);
        }
        if(root->right){
            flatten(root->right);
        }
        if(root->left){
            TreeNode* leaf = root->left;
            while (leaf->right) {
                leaf = leaf->right;
            }
            leaf->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
