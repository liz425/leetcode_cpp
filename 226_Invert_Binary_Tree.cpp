//
//  226_Invert_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "TreeNode.h"
using namespace std;


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL){
            TreeNode* swap = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(swap);
        }
        return root;
    }
};