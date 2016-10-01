//
//  328_Odd_Even_Linked_List.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next;
        ListNode* odd_head = NULL, *odd_cur = NULL, *even_head = NULL, *even_cur = NULL;
        bool isOdd = true;
        while(cur){
            next = cur->next;
            cur->next = NULL;
            if(isOdd){
                if(odd_head){
                    odd_cur->next = cur;
                    odd_cur = cur;
                }else{
                    odd_head = cur;
                    odd_cur = cur;
                }
            }else{
                if(even_head){
                    even_cur->next = cur;
                    even_cur = cur;
                }else{
                    even_head = cur;
                    even_cur = cur;
                }
            }
            cur = next;
            isOdd = !isOdd;
        }
        if(odd_cur){
            odd_cur->next = even_head;
        }
        return odd_head;
    }
};
