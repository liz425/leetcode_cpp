//
//  339_Nested_List_Weight_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/14/16.
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


class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        if(nestedList.empty())
            return 0;
        //Have to use const_iterator to iterate an const vector!!!!!
        stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> stk;
        stk.push(make_pair(nestedList.begin(), nestedList.end()));
        int sum = 0;
        while(!stk.empty()){
            if(stk.top().first == stk.top().second){
                stk.pop();
            }else{
                if(stk.top().first->isInteger()){
                    sum += stk.top().first->getInteger() * int(stk.size());
                    stk.top().first++;
                }else{
                    auto it = stk.top().first;
                    stk.top().first++;
                    stk.push(make_pair(it->getList().begin(), it->getList().end()));
                }
            }
        }
        return sum;
    }
};
