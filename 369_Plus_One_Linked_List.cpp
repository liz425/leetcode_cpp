//
//  369_Plus_One_Linked_List.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/7/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int carry = add(head);
        if(carry == 0){
            return head;
        }else{
            ListNode* pre = new ListNode(1);
            pre->next = head;
            return pre;
        }
    }
    int add(ListNode* head){
        if(head == NULL){
            return 1;
        }
        int carry = add(head->next);
        int ret = (head->val + carry) / 10;
        head->val = (head->val + carry) % 10;
        return ret;
    }
};
