//
//  270_Closest_Binary_Search_Tree_Value.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //iterative. T = O(logN)
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root){
            if(abs(closest - target) >= abs(root->val - target)){
                closest = root->val;
            }
            root = (target < root->val)? root->left : root->right;
        }
        return closest;
    }
};


class Solution {
    //recursive. T = O(logN)
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* child = (target < root->val)? root->left : root->right;
        if(!child){
            return root->val;
        }
        int childClosest = closestValue(child, target);
        return (abs(childClosest - target) < abs(root->val - target))? childClosest : root->val;
    }
};
