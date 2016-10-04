//
//  285_Inorder_Successor_in_BST.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
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