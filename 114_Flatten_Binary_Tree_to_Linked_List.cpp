//
//  114_Flatten_Binary_Tree_to_Linked_List.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution3 {
    //Brilliant solution from LeetCode.
    //Reverse 'pre-order' traversal. Thus we are actually build the linked list from bottom to top.
    //The insight here is that for reverse 'pre-order' traversal, we process child node before father node.
    //After we processed both children node, the 'left' and 'right' pointer of parent is not modified yet.
    //If we use pre-order traversal, we need to use a temp var to store parent->right.
    //Otherwise, when we call flatten(root->left), it will change 'root->right'.
    TreeNode* nextNode = NULL;
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = nextNode;
        root->left = NULL;
        nextNode = root;
    }
};


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
