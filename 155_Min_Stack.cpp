//
//  155_Min_Stack.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/25/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace  std;

class MinStack {
    //use 2 stacks, one for data, one for mins
public:
    stack<int> stk;
    stack<int> min;
    void push(int x) {
        stk.push(x);
        if(min.empty() || x <= min.top()){
            min.push(x);
        }
    }
    
    void pop() {
        if(stk.top() == min.top()){
            min.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if(min.empty())
            return 0;
        return min.top();
    }
};

/*
int main(){
    MinStack ss;
    ss.push(2);
    ss.push(0);
    ss.push(3);
    ss.push(0);
    ss.getMin();
    ss.pop();
    ss.getMin();
    ss.pop();
    ss.getMin();
    ss.pop();
    ss.getMin();
}
*/