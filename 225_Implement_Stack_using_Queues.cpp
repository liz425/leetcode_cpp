//
//  225_Implement_Stack_using_Queues.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


class Stack2 {
    //One Queues, push: O(n), pop: O(1)
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for(int i = 1; i < q.size(); i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }
    
    // Get the top element.
    int top() {
        return q.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

class Stack {
    //Two Queues, push: O(1), pop: O(n)
public:
    vector<queue<int>> qv;
    int sel;
    Stack(){
        queue<int> q;
        qv.push_back(q);
        qv.push_back(q);
        sel = 0;
    }
    // Push element x onto stack.
    void push(int x) {
        qv[sel].push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        while(qv[sel].size() > 1){
            qv[1 - sel].push(qv[sel].front());
            qv[sel].pop();
        }
        qv[sel].pop();
        sel = 1 - sel;
    }
    
    // Get the top element.
    int top() {
        int last = 0;
        while(!qv[sel].empty()){
            last = qv[sel].front();
            qv[1 - sel].push(last);
            qv[sel].pop();
        }
        sel = 1 - sel;
        return last;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return qv[sel].empty();
    }
};



