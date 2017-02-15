//
//  109_Convert_Sorted_List_to_Binary_Search_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/14/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while(cur){
            n++;
            cur = cur->next;
        }
        return helper(head, n);
    }
    TreeNode* helper(ListNode* head, int n){
        if(n == 0){
            return NULL;
        }
        int left = n / 2;
        ListNode* mid = head;
        while(left-- > 0){
            mid = mid->next;
        }
        TreeNode* current = new TreeNode(mid->val);
        current->left = helper(head, n / 2);
        current->right = helper(mid->next, n - n / 2 - 1);
        return current;
    }
};
