//
//  104_Maximum_Depth_of_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

/**
  Definition for a binary tree node.
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    int depthHelper(TreeNode* cur, int depth){
        if(cur == NULL){
            return depth - 1;
        }else{
            return max(depthHelper(cur->left, depth + 1), depthHelper(cur->right, depth + 1));
        }
    }
    int maxDepth(TreeNode* root) {
        return depthHelper(root, 1);
    }
};