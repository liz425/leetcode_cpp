//
//  235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"


class Solution {
public:
    TreeNode* lsa = NULL;
    int inOrder(TreeNode* parent, TreeNode* p, TreeNode* q){
        if(lsa != NULL){
            return 0;
        }
        int found = 0;
        
        if(parent->left != NULL){
            found += inOrder(parent->left, p, q);
        }
        
        if(parent == p || parent == q){
            found += 1;
        }
        
        if(parent->right != NULL){
            found +=  inOrder(parent->right, p, q);
        }
        
        if(found == 2){
            lsa = parent;
        }
        
        return found;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        inOrder(root, p, q);
        return lsa;
    }
};