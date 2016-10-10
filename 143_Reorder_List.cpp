//
//  143_Reorder_List.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)
            return;
        int size = 0;
        ListNode* cur = head;
        while(cur != NULL){
            size++;
            cur = cur->next;
        }
        //reverse the second half
        int half = (size + 1) / 2;
        cur = head;
        while(--half > 0){
            cur = cur->next;
        }
        ListNode* tail = cur->next;
        cur->next = NULL;
        ListNode* next;
        ListNode* pre = NULL;
        while(tail){
            next = tail->next;
            tail->next = pre;
            pre = tail;
            tail = next;
        }
        //now tail is NULL, pre is the real tail;
        tail = pre;
        //merge head and tail
        ListNode* cur1, *cur2;
        while(tail){
            cur1 = head;
            cur2 = tail;
            head = head->next;
            tail = tail->next;
            cur1->next = cur2;
            cur2->next = head;
        }
    }
};
