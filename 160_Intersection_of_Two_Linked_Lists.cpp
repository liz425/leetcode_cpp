//
//  160_Intersection_of_Two_Linked_Lists.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution2 {
    //More concise
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;
    }
};



class Solution {
    //could return earlier if no intersection
    //first traverse both linked list, get length of them and check if end to the same point
    //if have intersection, base on length different, synchronize them
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while(tmpA != NULL){
            lenA++;
            if(!tmpA->next){
                break;
            }
            tmpA = tmpA->next;
        }
        while(tmpB != NULL){
            lenB++;
            if(!tmpB->next){
                break;
            }
            tmpB = tmpB->next;
        }
        if(tmpA != tmpB){
            return NULL;
        }
        tmpA = headA;
        tmpB = headB;
        if(lenA > lenB){
            for(int i = 0; i < lenA - lenB; i++){
                tmpA = tmpA->next;
            }
        }else{
            for(int i = 0; i < lenB - lenA; i++){
                tmpB = tmpB->next;
            }
        }
        while(tmpA != tmpB){
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return tmpA;
    }
};