//
//  295_Find_Median_from_Data_Stream.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class MedianFinder {
    //Use heap to record the smaller half and larger half.
    //addNum: T = O(logn), n is the total numbers so far
    //findMedian: T = O(1)
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.size() > minHeap.size()){
            if(num >= maxHeap.top()){
                minHeap.push(num);
            }else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }else{
            if(minHeap.empty() || num <= minHeap.top()){
                maxHeap.push(num);
            }else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2){
            return maxHeap.top();
        }else{
            return (maxHeap.top() + minHeap.top()) * 0.5;
        }
    }
};
