//
//  124_Binary_Tree_Maximum_Path_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSubSum(root);
        return maxSum;
    }
    int maxSubSum(TreeNode *root){
        if(!root)
            return 0;
        int leftSum = maxSubSum(root->left);
        int rightSum = maxSubSum(root->right);
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return max(root->val + max(leftSum, rightSum), 0);
    }
};
