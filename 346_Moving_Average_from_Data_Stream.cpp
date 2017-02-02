//
//  346_Moving_Average_from_Data_Stream.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/21/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class MovingAverage {
    int _size;
    long sum;
    deque<int> dq;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
        sum = 0;
    }
    
    double next(int val) {
        if(dq.size() >= _size){
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(val);
        sum += val;
        return sum * 1.0 / dq.size();
    }
};
