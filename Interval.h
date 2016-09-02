//
//  Interval.h
//  leetcode_cpp
//
//  Created by Zhen Li on 8/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#ifndef Interval_h
#define Interval_h

/* Definition for an interval. */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


#endif /* Interval_h */

