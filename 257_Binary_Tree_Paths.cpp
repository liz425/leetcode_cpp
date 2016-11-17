
//
//  257_Binary_Tree_Paths.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
private:
    void DFS(vector<string>& result, string candid, TreeNode* root){
        if(root == NULL){
            return;
        }
        if(!candid.empty()){
            candid += "->";
        }
        candid += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(candid);
        }else{
            DFS(result, candid, root->left);
            DFS(result, candid, root->right);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        DFS(result, "", root);
        return result;
    }
};
