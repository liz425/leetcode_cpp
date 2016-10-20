//
//  237_Delete_Node_in_a_Linked_List.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node && node->next){
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
