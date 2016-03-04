//
//  141_Linked_List_Cycle.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>



//Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(fast == slow)
        return true;
    }
    return false;
  }
};