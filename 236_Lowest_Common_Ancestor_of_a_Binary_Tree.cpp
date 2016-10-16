//
//  236_Lowest_Common_Ancestor_of_a_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l && r)
            return root;
        else if(l)
            return l;
        else
            return r;
    }
};
