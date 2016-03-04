//
//  230_Kth_Smallest_Element_in_a_BST.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int remain = -1;
  int kthSmallest(TreeNode* root, int k) {
    int rtn = 0;
    if(root->left){
      rtn = kthSmallest(root->left, k);
    }else{
      remain = k;
    }
    
    if(remain == 0){
      return rtn;
    }else if(remain == 1){
      remain = 0;
      return root->val;
    }else{
      remain = remain - 1;
      if(root->right){
        rtn = kthSmallest(root->right, remain);
      }
    }
    return rtn;
  }
};