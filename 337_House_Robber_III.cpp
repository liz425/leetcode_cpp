//
//  337_House_Robber_III.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root)[0];
    }
    vector<int> dfs(TreeNode* root){    //vector<int> = {maxIncludeRoot, maxExcludeRoot}
        if(!root)
            return vector<int>{0, 0};
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        return vector<int>{max(l[1] + r[1] + root->val, l[0] + r[0]), l[0] + r[0]};
    }
};
