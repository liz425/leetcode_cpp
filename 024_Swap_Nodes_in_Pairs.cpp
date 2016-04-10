//
//  024_Swap_Nodes_in_Pairs.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include "ListNode.h"
using namespace std;


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* swap;
        ListNode* current = new ListNode(1);
        current->next = head;
        ListNode* new_head = current;
        while(current->next != NULL && current->next->next != NULL){
            swap = current->next;
            current->next = swap->next;
            swap->next = current->next->next;
            current->next->next = swap;
            current = current->next->next;
        }
        return new_head->next;
    }
};

//int main(void){
//    vector<int> array = {77,57,79,24,47,21,42,38,54,26,28,30,85,32,40,62,28,89,37,24,3,51,72,59,49,7,60,44,7,27,48,37,37,27,13,36,49,55,26,55};
//    ListNode* before_head;
//    for(int i = 0; i < (int)array.size(); i++){
//        ListNode* current;
//        current->val = array[i];
//    }
//}