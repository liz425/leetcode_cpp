//
//  098_Validate_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    int current = 0;
    bool started = false;
    bool isValidBST(TreeNode* root) {
        //in-order traverse the tree, check its monotonicity
        if(!root)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(started && current >= root->val)
            return false;
        current = root->val;
        started = true;
        return isValidBST(root->right);
    }
};


class Solution {
public:
    //NOT a good solution
    bool isValidBST(TreeNode* root) {
        int left = 0, right = 0;
        return helper(root, left, right);
    }
    bool helper(TreeNode* root, int& left, int& right){
        if(!root){
            return true;
        }
        left = root->val, right = root->val;
        int lr = root->val, rl = root->val;
        if(root->left && !helper(root->left, left, lr))
            return false;
        if(root->right && !helper(root->right, rl, right))
            return false;
        return (!root->left ||lr < root->val) && (!root->right || root->val < rl);
    }
};