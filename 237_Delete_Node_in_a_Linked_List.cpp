//
//  237_Delete_Node_in_a_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node != NULL && node->next != NULL){
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};