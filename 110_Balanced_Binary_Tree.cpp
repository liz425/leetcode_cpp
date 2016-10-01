//
//  110_Balanced_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"


class Solution {
public:
    int treeHeight(TreeNode* root){
        //O(n) time
        //return -1 when not balanced, otherwise return height
        if(root == NULL){
            return 0;
        }else{
            int left = treeHeight(root->left);
            if(left < 0){
                //if left is unbalanced, no need to check right.
                return -1;
            }
            int right = treeHeight(root->right);
            if(right >= 0 && left - right <= 1 && right - left <= 1){
                return ((left > right)? left : right) + 1;
            }else{
                return -1;
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        return (treeHeight(root) >= 0);
    }
};




