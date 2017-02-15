//
//  108_Convert_Sorted_Array_to_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size());
    }
    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start >= end){
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode* current = new TreeNode(nums[mid]);
        current->left = helper(nums, start, mid);
        current->right = helper(nums, mid + 1, end);
        return current;
    }
};

