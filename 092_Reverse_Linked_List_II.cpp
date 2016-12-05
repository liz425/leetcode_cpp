
//
//  092_Reverse_Linked_List_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 0; i < m - 1; ++i){
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for(int i = 0; i < n - m; ++i){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //add dummy
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        m++, n++;
        //record node[m-1], node[m] as tmp1, tmp2
        int i = 0;
        ListNode *tmp1 = NULL, *tmp2 = NULL;
        ListNode *pre = NULL, *next = NULL;
        while(head != NULL){
            i++;
            if(i <= m - 1){
                tmp1 = head;
                tmp2 = head->next;
                head = head->next;
            }else if(i < n){
                next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }else{
                next = head->next;
                head->next = pre;
                tmp1->next = head;
                tmp2->next = next;
                return dummy->next;     //memory leaks here
            }
        }
        return dummy->next;
    }
};
