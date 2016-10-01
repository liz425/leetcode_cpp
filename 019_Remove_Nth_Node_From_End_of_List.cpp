//
//  019_Remove_Nth_Node_From_End_of_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        //move fast forward by n nodes.
        while(n > 0){
            fast = fast->next;
            n--;
        }
        //Now fast is n nodes faster than slow
        //If fast is NULL, then SLOW is the nth node from the end. Thus just remove slow, return its next.
        if(fast == NULL)
            return slow->next;
        //IF fast is not NULL, move both fast and slow forward untill fast is the last non-NULL node.
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        //Now, slow is the (n+1)th node from the end.
        //Remove its next, return head.
        slow->next = slow->next->next;
        return head;
    }
};



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
