//
//  284_Peeking_Iterator.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/25/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    bool nextExist;
    int nextItem;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        bool nextExist = Iterator::hasNext();
        int nextItem = nextExist? Iterator::next() : 0;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextItem;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int result = nextItem;
        nextExist = Iterator::hasNext();
        nextItem = nextExist? Iterator::next() : 0;
        return result;
    }
    
    bool hasNext() const {
        return nextExist;
    }
};
