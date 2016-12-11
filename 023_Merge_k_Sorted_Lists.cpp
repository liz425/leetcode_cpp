//
//  023_Merge_k_Sorted_Lists.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class comparator{
public:
    bool operator()(ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
    //use a heap to store current heads of all list
    //it takes O(log K) time to get the smallest head (suppose average K linked list)
    //then remove that smallest head and add it's next.
    //loop until the heap is empty. Suppose average lenght of linked list is N
    //then overall time: O(N*K*logK)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right){
            return (left->val > right->val);
        };
        //Either way of implementation of comparator is OK
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        //priority_queue<ListNode*, vector<ListNode*>, comparator> heap;
        for(auto& node: lists){
            if(node != NULL)
                heap.push(node);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(!heap.empty()){
            current->next = heap.top();
            current = current->next;
            heap.pop();
            if(current->next != NULL){
                heap.push(current->next);
            }
        }
        current->next = NULL;
        current = dummy->next;
        delete dummy;
        return current;
    }
};

