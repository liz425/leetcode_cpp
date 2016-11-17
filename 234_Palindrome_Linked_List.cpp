
//
//  234_Palindrome_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include "ListNode.h"


class Solution2 {
    //Much elegant solution than previous one
    //T = O(n), Space = O(1)
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;   //record mid for later recovery the original Linklist
        slow->next = reverseList(slow->next);
        slow = slow->next;      //length of the later half should be equal or 1 less than the previous half
        bool result = true;
        while(slow != NULL){
            if(head->val != slow->val){
                result = false;
                break;
            }
            head = head->next;
            slow = slow->next;
        }
        mid->next = reverseList(mid->next);
        return result;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};




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
