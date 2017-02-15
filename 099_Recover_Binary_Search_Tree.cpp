//
//  099_Recover_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/14/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    TreeNode* minNode = NULL;
    TreeNode* maxNode = NULL;
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        if(minNode && maxNode){
            //cout << minNode->val << endl;
            //cout << maxNode->val << endl;
            swap(minNode->val, maxNode->val);
        }
    }
    pair<TreeNode*, TreeNode*> helper(TreeNode* root){
        TreeNode *localMin = root, *localMax = root;
        if(!root){
            return make_pair(localMin, localMax);
        }
        
        if(root->left){
            auto leftExtrem = helper(root->left);
            localMin = leftExtrem.first;
            if(root->val < leftExtrem.second->val){
                if(minNode == NULL || minNode->val > root->val){
                    minNode = root;
                }
                if(maxNode == NULL || maxNode->val < leftExtrem.second->val){
                    maxNode = leftExtrem.second;
                }
            }
        }
        
        if(root->right){
            auto rightExtrem = helper(root->right);
            localMax = rightExtrem.second;
            if(root->val > rightExtrem.first->val){
                if(minNode == NULL || minNode->val > rightExtrem.first->val){
                    minNode = rightExtrem.first;
                }
                if(maxNode == NULL || maxNode->val < root->val){
                    maxNode = root;
                }
            }
        }
        //cout << root->val << "  " << localMin->val << " " << localMax->val << endl;
        return make_pair(localMin, localMax);
    }
};
