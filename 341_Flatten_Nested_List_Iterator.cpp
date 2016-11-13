//
//  341_Flatten_Nested_List_Iterator.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/9/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    //change to const_iterator
    stack<vector<NestedInteger>::const_iterator> begins;
    stack<vector<NestedInteger>::const_iterator> ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        hasNext();
        //stack.top() returns a referrence, thus we could use stack.top()++ to directly modify stack element
        return (begins.top()++)->getInteger();
    }
    
    bool hasNext() {
        while(!begins.empty()){
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }else{
                auto it = begins.top();
                if(it->isInteger()){
                    return true;
                }
                //update stack top, stack always store the iterator that will be used next time
                //stack.top() returns a referrence, just update it.
                begins.top()++;
                begins.push(it->getList().begin());
                ends.push(it->getList().end());
            }
        }
        return false;
    }
};
