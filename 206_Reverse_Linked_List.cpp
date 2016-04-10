//
//  206_Reverse_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"

class Solution {
    //iterative solution
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        while(head != NULL){
            ListNode * tmp_next = head->next;
            head->next = prev;
            prev = head;
            head = tmp_next;
        }
        return prev;
    }
};
