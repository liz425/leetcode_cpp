
//
//  234_Palindrome_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"


class Solution {
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
    bool isPalindrome(ListNode* head) {
        //get length of linked list
        ListNode* cur = head;
        int len = 0;
        while(cur != NULL){
            len++;
            cur = cur->next;
        }
        int i = 1;
        cur = head;
        //locating the middle point of the list
        while(i++ < (len + 1) / 2){
            cur = cur->next;
        }
        ListNode* tail;
        //Distinguish even and odd situation
        if(len % 2){
            tail = reverseList(cur);
        }else{
            if(cur == NULL){
                return true;
            }
            tail = cur->next;
            cur->next = NULL;
            tail = reverseList(tail);
        }
        while(head != NULL && tail != NULL){
            if(head->val != tail->val){
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return (head == tail);
    }
};