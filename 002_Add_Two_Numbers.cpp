//
//  002_Add_Two_Numbers.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 || l2){
            int sum = carry + (l1? l1->val : 0) + (l2? l2->val : 0);
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next;
            l1 = l1? l1->next : NULL;
            l2 = l2? l2->next : NULL;
        }
        if(carry){
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
