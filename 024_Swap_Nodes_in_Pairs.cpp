//
//  024_Swap_Nodes_in_Pairs.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //recursion solution, but this may not be real constant space, since the recursion stack may consume O(n) space.
    //However, it's simple and concise.
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *second = head->next;
        head->next = swapPairs(second->next);
        second->next = head;
        return second;
    }
};



class Solution {
    //This can be generalized as 025_Reverse_Nodes_in_k_Group.cpp
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy, *first, *second;
        while(current->next && current->next->next){
            first = current->next;
            second = first->next;
            first->next = second->next;
            current->next = second;
            second->next = first;
            current = first;
        }
        current = dummy->next;
        delete dummy;
        return current;
    }
};


/*
int main(void){
    vector<int> array = {77,57,79,24,47,21,42,38,54,26,28,30,85,32,40,62,28,89,37,24,3,51,72,59,49,7,60,44,7,27,48,37,37,27,13,36,49,55,26,55};
    for(int i = 0; i < (int)array.size(); i++){
        ListNode* current;
        current->val = array[i];
    }
}
*/
