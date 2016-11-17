//
//  285_Inorder_Successor_in_BST.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //T = O(h), h is height of tree, faster than previous solutions
    //find the smallest node that is larger than p->val, record the lastest one
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candid = NULL;
        while(root){
            if(root->val > p->val){
                candid = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return candid;
    }
};


class Solution2 {
    //T = O(h), h is height of tree
    //If p has a right subtree, then get its successor from there. Otherwise do a regular search from root to p but remember
    //the node of the last left-turn and return that.
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
            p = p->right;
            while(p->left){
                p = p->left;
            }
            return p;
        }
        TreeNode* candid = NULL;
        while(p != root){
            if(p->val < root->val){
                candid = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return candid;
    }
};



class Solution {
    //Just traversal the tree, T = O(n), n is number of nodes
public:
    TreeNode* pre = NULL;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
        if(!root)
            return NULL;
        TreeNode* leftAns = inorderSuccessor(root->left, p);
        if(leftAns)
            return leftAns;
        if(pre == p)
            return root;
        pre = root;
        return inorderSuccessor(root->right, p);
    }
};
