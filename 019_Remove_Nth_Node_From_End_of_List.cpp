//
//  019_Remove_Nth_Node_From_End_of_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        int k = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && k < n){
            fast = fast->next;
            k++;
        }
        if(k < n){
            return slow->next;
        }else{
            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
        }
        return head;
    }
};