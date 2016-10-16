//
//  098_Validate_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //in-order traverse the tree, check its monotonicity
public:
    int last = 0;  //last visited item. If currently still a valid BST, then last should be the largest element
    bool isInit = true; //for the first element, do not require to be larger the last one
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(root->left && !isValidBST(root->left))
            return false;
        if(!isInit && last >= root->val)
            return false;
        last = root->val;
        isInit = false;
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
