//
//  138_Copy_List_with_Random_Pointer.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/11/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        RandomListNode *newNode, *curNode = head;;
        //duplicate node, set up next pointer
        while(curNode){
            newNode = new RandomListNode(curNode->label);
            newNode->next = curNode->next;
            curNode->next = newNode;
            curNode = newNode->next;
        }
        //set up random pointer
        curNode = head;
        while(curNode){
            //check if random is NULL
            curNode->next->random = curNode->random? curNode->random->next : NULL;
            curNode = curNode->next->next;
        }
        //break current list into two: original list and duplicated list
        curNode = head;
        RandomListNode *newHead = curNode->next;
        RandomListNode *newCur = newHead;
        while(curNode){
            curNode->next = newCur->next;
            newCur->next = newCur->next? newCur->next->next : NULL;
            curNode = curNode->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};
