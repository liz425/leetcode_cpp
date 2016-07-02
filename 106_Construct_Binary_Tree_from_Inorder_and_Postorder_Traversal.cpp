//
//  106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hmap;
        int len = (int)inorder.size();
        for(int i = 0; i < len; ++i){
            hmap[inorder[i]] = i;
        }
        return buildTreeHelper(hmap, 0, (int)inorder.size(), postorder, 0, (int)postorder.size());
    }
    
    TreeNode* buildTreeHelper(unordered_map<int, int>& hmap, int p, int q, vector<int>& postorder, int i, int j){
        if(i >= j){
            return NULL;
        }
        TreeNode* current = new TreeNode(postorder[j - 1]);
        int me = hmap[postorder[j - 1]];
        int right = int(q - 1 - me);
        current->left = buildTreeHelper(hmap, p, me, postorder, i, j - 1 - right);
        current->right = buildTreeHelper(hmap, me + 1, q, postorder, j - 1 - right, j - 1);
        return current;
    }
};
