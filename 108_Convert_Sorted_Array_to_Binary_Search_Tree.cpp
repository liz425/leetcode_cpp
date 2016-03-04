//
//  108_Convert_Sorted_Array_to_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, (int)nums.size() - 1);
  }
  
  TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int i, int j){
    int middle = (i + j + 1)/2;
    if(i > j){
      return NULL;
    }
    TreeNode* current = new TreeNode(nums[middle]);
    current->left = sortedArrayToBSTHelper(nums, i, middle - 1);
    current->right = sortedArrayToBSTHelper(nums, middle + 1, j);
    return current;
  }
};