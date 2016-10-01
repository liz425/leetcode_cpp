//
//  100_Same_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }else if(p != NULL && q != NULL && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
            return true;
        }else{
            return false;
        }
    }
};