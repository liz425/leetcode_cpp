//
//  206_Reverse_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"


class Solution2 {
    //recursive solution
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }else{
            ListNode* new_head = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return new_head;
        }
    }
};



class Solution {
    //iterative solution
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = NULL, *next = NULL;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
