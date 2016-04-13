//
//  101_Symmetric_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

class Solution {
public:
    bool isSame(TreeNode* left, TreeNode* right){
        //use 3 nested if-else to assign various priority to the if-condition
        //since compiler don't gurantee the order of judging conditions in: a && b && c
        if(left != NULL && right != NULL){
            if(left->val == right->val){
                if(isSame(left->left, right->right)){
                    if(isSame(left->right, right->left)){
                        return true;
                    }
                }
            }
            return false;
        }else{
            return (left == NULL && right == NULL);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSame(root, root);
    }
};