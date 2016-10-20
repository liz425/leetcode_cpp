//
//  025_Reverse_Nodes_in_k_Group.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        //create dummy
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *preSec = dummy, *nextSec;
        ListNode *start = dummy, *end = dummy;
        int cnt = k;
        while(cnt > 0 && end->next){
            cnt--;
            end = end->next;
            if(cnt == 0){   //fill out a new section
                cnt = k;
                nextSec = end->next;
                start = preSec->next;
                preSec->next = end;
                preSec = start;
                ListNode *pre = nextSec, *next;
                while(start != nextSec){   //(start != end->next) is wrong because when start == end, end->next will be changed
                    next = start->next;
                    start->next = pre;
                    pre = start;
                    start = next;
                }
                end = preSec;
            }
        }
        return dummy->next;
    }
};
