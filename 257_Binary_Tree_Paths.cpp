
//
//  257_Binary_Tree_Paths.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;


class Solution {
public:
    void helper(TreeNode* root, string str, vector<string>& vec){
        if(root != NULL){
            if(!str.empty()){
                str += "->";
            }
            str += to_string(root->val);
            if(root->left == NULL && root->right == NULL && !str.empty()){
                vec.push_back(str);
            }else{
                helper(root->left, str, vec);
                helper(root->right, str, vec);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string str = "";
        helper(root, str, vec);
        return vec;
    }
};