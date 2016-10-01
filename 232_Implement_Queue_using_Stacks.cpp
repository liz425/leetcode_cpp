//
//  232_Implement_Queue_using_Stacks.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> stk_in;
    stack<int> stk_out;
    // Push element x to the back of queue.
    void push(int x) {
        stk_in.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(stk_out.empty()){
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
        stk_out.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if(stk_out.empty()){
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
        return stk_out.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return (stk_in.empty() && stk_out.empty());
    }
};