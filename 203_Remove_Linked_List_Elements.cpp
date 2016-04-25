//
//  203_Remove_Linked_List_Elements.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* first = prev;
        while(head != NULL){
            if(head->val == val){
                prev->next = head->next;
            }else{
                prev = head;
            }
            head = head->next;
        }
        return first->next;
    }
};