//
//  21_Merge_Two_Sorted_Lists.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* current = &head;
        while(l1 && l2){
            if(l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = (l1)? l1 : l2;
        return head.next;
    }
};