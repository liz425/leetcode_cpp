//
//  112_Path_Sum.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }else if(root->left == NULL && root->right == NULL){
            return (root->val == sum);
        }else{
            return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
        }
    }
};