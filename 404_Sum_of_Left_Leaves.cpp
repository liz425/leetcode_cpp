//
//  404_Sum_of_Left_Leaves.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Prefer not use global variable
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return DFS(root, false);
    }
    int DFS(TreeNode* root, bool isLeft){
        if(!root){
            return 0;
        }else if(isLeft && !root->left && !root->right){
            return root->val;
        }else{
            return DFS(root->left, true) + DFS(root->right, false);
        }
    }
};



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
