//
//  173_Binary_Search_Tree_Iterator.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class BSTIterator {
    //conventional way of in-order traversal
    //initially go to the left-most node
    //Once visited a node, remove it from stack and process its right node as a new root
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }
    
    void pushAllLeft(TreeNode* cur){
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* result = stk.top();
        stk.pop();
        pushAllLeft(result->right);
        return result->val;
    }
};


class BSTIterator2 {
    //Novel way of tree traversal
    //Can easily switch from pre-order, in-order and post-order tree traversal.
public:
    stack<pair<TreeNode*, int>> stk;
    BSTIterator2(TreeNode *root) {
        if(root){
            stk.push(make_pair(root, 0));
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        if(stk.empty())
            return 0;
        while(stk.top().second != 1){
            TreeNode* top = stk.top().first;
            stk.pop();
            if(top->right){
                stk.push(make_pair(top->right, 0));
            }
            stk.push(make_pair(top, 1));
            if(top->left){
                stk.push(make_pair(top->left, 0));
            }
        }
        int result = stk.top().first->val;
        stk.pop();
        return result;
    }
};

