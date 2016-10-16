//
//  235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //same idea of Solution2
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = min(p->val, q->val);
        int right = max(p->val, q->val);
        while(root){
            if(root->val > right)
                root = root->left;
            else if(root->val < left)
                root = root->right;
            else
                return root;
        }
        return root;
    }
};



class Solution2 {
    //p and q should located in different subtree of LCA, or one of them is LCA
    //Thus if both p and q located in the same subtree of cur_node, cur_node could not be the LCA
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val > root->val && q->val > root->val){
                root = root->right;
            }else if(p->val < root->val && q->val < root->val){
                root = root->left;
            }else{
                return root;
            }
        }
        //If not found, return NULL
        return root;
    }
};


class Solution {
public:
    TreeNode* lsa = NULL;
    int inOrder(TreeNode* parent, TreeNode* p, TreeNode* q){
        if(lsa != NULL){
            return 0;
        }
        int found = 0;
        
        if(parent->left != NULL){
            found += inOrder(parent->left, p, q);
        }
        
        if(parent == p || parent == q){
            found += 1;
        }
        
        if(parent->right != NULL){
            found +=  inOrder(parent->right, p, q);
        }
        
        if(found == 2){
            lsa = parent;
        }
        
        return found;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        inOrder(root, p, q);
        return lsa;
    }
};
