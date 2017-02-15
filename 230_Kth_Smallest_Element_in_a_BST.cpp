//
//  230_Kth_Smallest_Element_in_a_BST.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //pre-order traversal
    //Notice that in the original definition of the kthSmallest function, the argument 'k' is passed by value, not by reference.
    //Here for easier recurrsion, we pass 'k' as reference.
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(!root){
            return 0;
        }
        int leftVal = kthSmallest(root->left, k);
        if(k < 1){
            return leftVal;
        }else if(k == 1){
            k--;
            return root->val;
        }else{
            k--;
            return kthSmallest(root->right, k);
        }
    }
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
