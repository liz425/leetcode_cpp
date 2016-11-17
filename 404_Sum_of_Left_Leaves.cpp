//
//  404_Sum_of_Left_Leaves.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    void DFS(TreeNode* root, int isLeft, int& sum){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            sum += isLeft? root->val : 0;
        }else{
            DFS(root->left, 1, sum);
            DFS(root->right, 0, sum);
        }
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};
