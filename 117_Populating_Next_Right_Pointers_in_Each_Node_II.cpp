//
//  117_Populating_Next_Right_Pointers_in_Each_Node_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Just one while-loop is enough
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *father = root;
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *son = dummy;
        while(father){
            if(father->left){
                son->next = father->left;
                son = son->next;
            }
            if(father->right){
                son->next = father->right;
                son = son->next;
            }
            if(father->next){
                father = father->next;
            }else{
                father = dummy->next;
                son = dummy;
                dummy->next = NULL;
            }
        }
        delete dummy;
    }
};



class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *father = root;
        TreeLinkNode *dummy = new TreeLinkNode(0);
        TreeLinkNode *son = dummy;
        while(father){
            while(father){
                if(father->left){
                    son->next = father->left;
                    son = son->next;
                }
                if(father->right){
                    son->next = father->right;
                    son = son->next;
                }
                father = father->next;
            }
            father = dummy->next;
            son = dummy;
            dummy->next = NULL;
        }
        delete dummy;
    }
};


