//
//  298_Binary_Tree_Longest_Consecutive_Sequence.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/21/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    int maxLen = 0;
public:
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return maxLen;
    }
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftLen = 1, rightLen = 1;
        if(root->left){
            leftLen = helper(root->left);
            if(root->val == root->left->val - 1){
                leftLen++;
            }else{
                leftLen = 1;
            }
        }
        if(root->right){
            rightLen = helper(root->right);
            if(root->val == root->right->val - 1){
                rightLen++;
            }else{
                rightLen = 1;
            }
        }
        maxLen = max(maxLen, max(leftLen, rightLen));
        return max(leftLen, rightLen);
    }
};
